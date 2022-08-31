#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

using namespace std;
namespace testing{
namespace gmock_matchers_test {
using testing::internal::DummyMatchResultListener;
using testing::internal::ElementMatcherPair;
using testing::internal::ElementMatcherPairs;
using testing::internal::ElementsAreArrayMatcher;
using testing::internal::ExplainMatchFailureTupleTo;
using testing::internal::FloatingEqMatcher;
using testing::internal::FormatMatcherDescription;
using testing::internal::IsReadableTypeName;
using testing::internal::MatchMatrix;
using testing::internal::PredicateFormatterFromMatcher;
using testing::internal::RE;
using testing::internal::StreamMatchResultListener;
using testing::internal::Strings;

// Helper for testing container-valued matchers in mock method context. It is
// important to test matchers in this context, since it requires additional type
// deduction beyond what EXPECT_THAT does, thus making it more restrictive.
struct ContainerHelper {
  MOCK_METHOD1(Call, void(std::vector<std::unique_ptr<int>>));
};

std::vector<std::unique_ptr<int>> MakeUniquePtrs(const std::vector<int>& ints) {
  std::vector<std::unique_ptr<int>> pointers;
  for (int i : ints) pointers.emplace_back(new int(i));
  return pointers;
}

// Returns the description of the given matcher.
template <typename T>
std::string Describe(const Matcher<T>& m) {
  return DescribeMatcher<T>(m);
}

// Returns the description of the negation of the given matcher.
template <typename T>
std::string DescribeNegation(const Matcher<T>& m) {
  return DescribeMatcher<T>(m, true);
}

// Returns the reason why x matches, or doesn't match, m.
template <typename MatcherType, typename Value>
std::string Explain(const MatcherType& m, const Value& x) {
  StringMatchResultListener listener;
  ExplainMatchResult(m, x, &listener);
  return listener.str();
}

TEST(IsEmptyTest, ImplementsIsEmpty) {
  vector<int> container;
  EXPECT_THAT(container, IsEmpty());
  container.push_back(0);
  EXPECT_THAT(container, Not(IsEmpty()));
  container.push_back(1);
  EXPECT_THAT(container, Not(IsEmpty()));
}

TEST(IsEmptyTest, WorksWithString) {
  std::string text;
  EXPECT_THAT(text, IsEmpty());
  text = "foo";
  EXPECT_THAT(text, Not(IsEmpty()));
  text = std::string("\0", 1);
  EXPECT_THAT(text, Not(IsEmpty()));
}

TEST(IsEmptyTest, CanDescribeSelf) {
  Matcher<vector<int> > m = IsEmpty();
  EXPECT_EQ("is empty", Describe(m));
  EXPECT_EQ("isn't empty", DescribeNegation(m));
}

TEST(IsEmptyTest, ExplainsResult) {
  Matcher<vector<int> > m = IsEmpty();
  vector<int> container;
  EXPECT_EQ("", Explain(m, container));
  container.push_back(0);
  EXPECT_EQ("whose size is 1", Explain(m, container));
}

TEST(IsEmptyTest, WorksWithMoveOnly) {
  ContainerHelper helper;
  EXPECT_CALL(helper, Call(IsEmpty()));
  helper.Call({});
}

TEST(IsTrueTest, IsTrueIsFalse) {
  EXPECT_THAT(true, IsTrue());
  EXPECT_THAT(false, IsFalse());
  EXPECT_THAT(true, Not(IsFalse()));
  EXPECT_THAT(false, Not(IsTrue()));
  EXPECT_THAT(0, Not(IsTrue()));
  EXPECT_THAT(0, IsFalse());
  EXPECT_THAT(nullptr, Not(IsTrue()));
  EXPECT_THAT(nullptr, IsFalse());
  EXPECT_THAT(-1, IsTrue());
  EXPECT_THAT(-1, Not(IsFalse()));
  EXPECT_THAT(1, IsTrue());
  EXPECT_THAT(1, Not(IsFalse()));
  EXPECT_THAT(2, IsTrue());
  EXPECT_THAT(2, Not(IsFalse()));
  int a = 42;
  EXPECT_THAT(a, IsTrue());
  EXPECT_THAT(a, Not(IsFalse()));
  EXPECT_THAT(&a, IsTrue());
  EXPECT_THAT(&a, Not(IsFalse()));
  EXPECT_THAT(false, Not(IsTrue()));
  EXPECT_THAT(true, Not(IsFalse()));
  EXPECT_THAT(std::true_type(), IsTrue());
  EXPECT_THAT(std::true_type(), Not(IsFalse()));
  EXPECT_THAT(std::false_type(), IsFalse());
  EXPECT_THAT(std::false_type(), Not(IsTrue()));
  EXPECT_THAT(nullptr, Not(IsTrue()));
  EXPECT_THAT(nullptr, IsFalse());
  std::unique_ptr<int> null_unique;
  std::unique_ptr<int> nonnull_unique(new int(0));
  EXPECT_THAT(null_unique, Not(IsTrue()));
  EXPECT_THAT(null_unique, IsFalse());
  EXPECT_THAT(nonnull_unique, IsTrue());
  EXPECT_THAT(nonnull_unique, Not(IsFalse()));
}

TEST(SizeIsTest, ImplementsSizeIs) {
  vector<int> container;
  EXPECT_THAT(container, SizeIs(0));
  EXPECT_THAT(container, Not(SizeIs(1)));
  container.push_back(0);
  EXPECT_THAT(container, Not(SizeIs(0)));
  EXPECT_THAT(container, SizeIs(1));
  container.push_back(0);
  EXPECT_THAT(container, Not(SizeIs(0)));
  EXPECT_THAT(container, SizeIs(2));
}

TEST(SizeIsTest, WorksWithMap) {
  map<std::string, int> container;
  EXPECT_THAT(container, SizeIs(0));
  EXPECT_THAT(container, Not(SizeIs(1)));
  container.insert(make_pair("foo", 1));
  EXPECT_THAT(container, Not(SizeIs(0)));
  EXPECT_THAT(container, SizeIs(1));
  container.insert(make_pair("bar", 2));
  EXPECT_THAT(container, Not(SizeIs(0)));
  EXPECT_THAT(container, SizeIs(2));
}

TEST(SizeIsTest, WorksWithReferences) {
  vector<int> container;
  Matcher<const vector<int>&> m = SizeIs(1);
  EXPECT_THAT(container, Not(m));
  container.push_back(0);
  EXPECT_THAT(container, m);
}

TEST(SizeIsTest, WorksWithMoveOnly) {
  ContainerHelper helper;
  EXPECT_CALL(helper, Call(SizeIs(3)));
  helper.Call(MakeUniquePtrs({1, 2, 3}));
}

// SizeIs should work for any type that provides a size() member function.
// For example, a size_type member type should not need to be provided.
struct MinimalistCustomType {
  int size() const { return 1; }
};

TEST(SizeIsTest, WorksWithMinimalistCustomType) {
  MinimalistCustomType container;
  EXPECT_THAT(container, SizeIs(1));
  EXPECT_THAT(container, Not(SizeIs(0)));
}

TEST(SizeIsTest, CanDescribeSelf) {
  Matcher<vector<int> > m = SizeIs(2);
  EXPECT_EQ("size is equal to 2", Describe(m));
  EXPECT_EQ("size isn't equal to 2", DescribeNegation(m));
}

TEST(SizeIsTest, ExplainsResult) {
  Matcher<vector<int> > m1 = SizeIs(2);
  Matcher<vector<int> > m2 = SizeIs(Lt(2u));
  Matcher<vector<int> > m3 = SizeIs(AnyOf(0, 3));
  Matcher<vector<int> > m4 = SizeIs(Gt(1u));
  vector<int> container;
  EXPECT_EQ("whose size 0 doesn't match", Explain(m1, container));
  EXPECT_EQ("whose size 0 matches", Explain(m2, container));
  EXPECT_EQ("whose size 0 matches", Explain(m3, container));
  EXPECT_EQ("whose size 0 doesn't match", Explain(m4, container));
  container.push_back(0);
  container.push_back(0);
  EXPECT_EQ("whose size 2 matches", Explain(m1, container));
  EXPECT_EQ("whose size 2 doesn't match", Explain(m2, container));
  EXPECT_EQ("whose size 2 doesn't match", Explain(m3, container));
  EXPECT_EQ("whose size 2 matches", Explain(m4, container));
}

// Tests that ASSERT_THAT() and EXPECT_THAT() work when the value
// matches the matcher.
TEST(MatcherAssertionTest, WorksWhenMatcherIsSatisfied) {
  ASSERT_THAT(5, Ge(2)) << "This should succeed.";
  ASSERT_THAT("Foo", EndsWith("oo"));
  EXPECT_THAT(2, AllOf(Le(7), Ge(0))) << "This should succeed too.";
  EXPECT_THAT("Hello", StartsWith("Hell"));
}

}
}

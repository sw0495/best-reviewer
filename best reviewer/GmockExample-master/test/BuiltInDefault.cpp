#include <gmock/gmock.h>
#include <memory>

//using namespace std;
using namespace testing;
using ::testing::internal::BuiltInDefaultValue;

// Tests that BuiltInDefaultValue<T*>::Get() returns NULL.
TEST(BuiltInDefaultValueTest, IsNullForPointerTypes) {
  EXPECT_TRUE(BuiltInDefaultValue<int*>::Get() == nullptr);
  EXPECT_TRUE(BuiltInDefaultValue<const char*>::Get() == nullptr);
  EXPECT_TRUE(BuiltInDefaultValue<void*>::Get() == nullptr);
}

// Tests that BuiltInDefaultValue<T*>::Exists() return true.
TEST(BuiltInDefaultValueTest, ExistsForPointerTypes) {
  EXPECT_TRUE(BuiltInDefaultValue<int*>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<const char*>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<void*>::Exists());
}

// Tests that BuiltInDefaultValue<T>::Get() returns 0 when T is a
// built-in numeric type.
TEST(BuiltInDefaultValueTest, IsZeroForNumericTypes) {
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned char>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<signed char>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<char>::Get());
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned short>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed short>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<short>::Get());  // NOLINT
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned int>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<signed int>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<int>::Get());
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<long>::Get());  // NOLINT
  EXPECT_EQ(0U, BuiltInDefaultValue<unsigned long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<signed long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<long long>::Get());  // NOLINT
  EXPECT_EQ(0, BuiltInDefaultValue<float>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<double>::Get());
}

// Tests that BuiltInDefaultValue<T>::Exists() returns true when T is a
// built-in numeric type.
TEST(BuiltInDefaultValueTest, ExistsForNumericTypes) {
  EXPECT_TRUE(BuiltInDefaultValue<unsigned char>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<signed char>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<char>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<unsigned short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<short>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<unsigned int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<signed int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<int>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<unsigned long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<unsigned long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<signed long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<long long>::Exists());  // NOLINT
  EXPECT_TRUE(BuiltInDefaultValue<float>::Exists());
  EXPECT_TRUE(BuiltInDefaultValue<double>::Exists());
}

// Tests that BuiltInDefaultValue<bool>::Get() returns false.
TEST(BuiltInDefaultValueTest, IsFalseForBool) {
  EXPECT_FALSE(BuiltInDefaultValue<bool>::Get());
}

// Tests that BuiltInDefaultValue<bool>::Exists() returns true.
TEST(BuiltInDefaultValueTest, BoolExists) {
  EXPECT_TRUE(BuiltInDefaultValue<bool>::Exists());
}

// Tests that BuiltInDefaultValue<T>::Get() returns "" when T is a
// string type.
TEST(BuiltInDefaultValueTest, IsEmptyStringForString) {
  EXPECT_EQ("", BuiltInDefaultValue< ::std::string>::Get());
}

// Tests that BuiltInDefaultValue<T>::Exists() returns true when T is a
// string type.
TEST(BuiltInDefaultValueTest, ExistsForString) {
  EXPECT_TRUE(BuiltInDefaultValue< ::std::string>::Exists());
}

// Tests that BuiltInDefaultValue<const T>::Get() returns the same
// value as BuiltInDefaultValue<T>::Get() does.
TEST(BuiltInDefaultValueTest, WorksForConstTypes) {
  EXPECT_EQ("", BuiltInDefaultValue<const std::string>::Get());
  EXPECT_EQ(0, BuiltInDefaultValue<const int>::Get());
  EXPECT_TRUE(BuiltInDefaultValue<char* const>::Get() == nullptr);
  EXPECT_FALSE(BuiltInDefaultValue<const bool>::Get());
}

// A type that's default constructible.
class MyDefaultConstructible {
 public:
  MyDefaultConstructible() : value_(42) {}

  int value() const { return value_; }

 private:
  int value_;
};

// A type that's not default constructible.
class MyNonDefaultConstructible {
 public:
  // Does not have a default ctor.
  explicit MyNonDefaultConstructible(int a_value) : value_(a_value) {}

  int value() const { return value_; }

 private:
  int value_;
};


TEST(BuiltInDefaultValueTest, ExistsForDefaultConstructibleType) {
  EXPECT_TRUE(BuiltInDefaultValue<MyDefaultConstructible>::Exists());
}

TEST(BuiltInDefaultValueTest, IsDefaultConstructedForDefaultConstructibleType) {
  EXPECT_EQ(42, BuiltInDefaultValue<MyDefaultConstructible>::Get().value());
}


TEST(BuiltInDefaultValueTest, DoesNotExistForNonDefaultConstructibleType) {
  EXPECT_FALSE(BuiltInDefaultValue<MyNonDefaultConstructible>::Exists());
}

// Tests that DefaultValue<T>::IsSet() is false initially.
TEST(DefaultValueTest, IsInitiallyUnset) {
  EXPECT_FALSE(DefaultValue<int>::IsSet());
  EXPECT_FALSE(DefaultValue<MyDefaultConstructible>::IsSet());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::IsSet());
}

// Tests that DefaultValue<T> can be set and then unset.
TEST(DefaultValueTest, CanBeSetAndUnset) {
  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::Exists());

  DefaultValue<int>::Set(1);
  DefaultValue<const MyNonDefaultConstructible>::Set(
      MyNonDefaultConstructible(42));

  EXPECT_EQ(1, DefaultValue<int>::Get());
  EXPECT_EQ(42, DefaultValue<const MyNonDefaultConstructible>::Get().value());

  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_TRUE(DefaultValue<const MyNonDefaultConstructible>::Exists());

  DefaultValue<int>::Clear();
  DefaultValue<const MyNonDefaultConstructible>::Clear();

  EXPECT_FALSE(DefaultValue<int>::IsSet());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::IsSet());

  EXPECT_TRUE(DefaultValue<int>::Exists());
  EXPECT_FALSE(DefaultValue<const MyNonDefaultConstructible>::Exists());
}

TEST(DefaultValueTest, GetWorksForMoveOnlyIfSet) {
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Exists());
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Get() == nullptr);
  DefaultValue<std::unique_ptr<int>>::SetFactory([] {
    return std::unique_ptr<int>(new int(42));
  });
  EXPECT_TRUE(DefaultValue<std::unique_ptr<int>>::Exists());
  std::unique_ptr<int> i = DefaultValue<std::unique_ptr<int>>::Get();
  EXPECT_EQ(42, *i);
}

class MockClass {
 public:
  MockClass() {}
  MOCK_METHOD(int, IntFunc, (bool));  
  
};

// Tests that DoDefault() returns the built-in default value for the
// return type by default.
TEST(DoDefaultTest, ReturnsBuiltInDefaultValueByDefault) {
  MockClass mock;
  EXPECT_CALL(mock, IntFunc(_))
      .WillOnce(DoDefault());
  EXPECT_EQ(0, mock.IntFunc(true));
}

// Tests that DoDefault() does the action specified by ON_CALL().
TEST(DoDefaultTest, DoesWhatOnCallSpecifies) {
  MockClass mock;
  ON_CALL(mock, IntFunc(_))
      .WillByDefault(Return(2));
  EXPECT_CALL(mock, IntFunc(_))
      .WillOnce(DoDefault());
  EXPECT_EQ(2, mock.IntFunc(false));
}





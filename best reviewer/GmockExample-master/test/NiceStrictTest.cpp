
#include <gmock/gmock.h>
#include <gtest/gtest.h>

//using namespace std;
using namespace testing;


class Foo {
 public:
  virtual ~Foo() {}

  virtual void DoThis() = 0;
  virtual int DoThat(bool flag) = 0;
};

class MockFoo : public Foo {
 public:
  MockFoo() {}
  void Delete() { delete this; }

  MOCK_METHOD(void, DoThis, ());
  MOCK_METHOD(int, DoThat, (bool));
};


// Tests that a raw mock generates warnings for uninteresting calls.
TEST(RawMockTest, WarningForUninterestingCall) {
  MockFoo raw_foo;

  raw_foo.DoThis();
  raw_foo.DoThat(true);
}

// Tests that a raw mock generates warnings for uninteresting calls
// that delete the mock object.
TEST(RawMockTest, WarningForUninterestingCallAfterDeath) {

  MockFoo* const raw_foo = new MockFoo;

  ON_CALL(*raw_foo, DoThis())
      .WillByDefault(Invoke(raw_foo, &MockFoo::Delete));

  raw_foo->DoThis();
}

TEST(RawMockTest, IsNaggy_IsNice_IsStrict) {
  MockFoo raw_foo;
  EXPECT_TRUE(Mock::IsNaggy(&raw_foo));
  EXPECT_FALSE(Mock::IsNice(&raw_foo));
  EXPECT_FALSE(Mock::IsStrict(&raw_foo));
}


// Tests that a nice mock generates warnings for uninteresting calls.
TEST(NiceMockTest, WarningForUninterestingCall) {
  NiceMock<MockFoo> nice_foo;

  nice_foo.DoThis();
  nice_foo.DoThat(true);
}

// Tests that a nice mock generates warnings for uninteresting calls
// that delete the mock object.
TEST(NiceMockTest, WarningForUninterestingCallAfterDeath) {

  NiceMock<MockFoo>* const nice_foo = new NiceMock<MockFoo>;

  ON_CALL(*nice_foo, DoThis())
      .WillByDefault(Invoke(nice_foo, &MockFoo::Delete));

  nice_foo->DoThis();
}


// Tests that a strict mock generates warnings for uninteresting calls.
TEST(StrictMockTest, WarningForUninterestingCall) {
  StrictMock<MockFoo> strict_foo;

  strict_foo.DoThis();
  strict_foo.DoThat(true);
}

// Tests that a strict mock generates warnings for uninteresting calls
// that delete the mock object.
TEST(StrictMockTest, WarningForUninterestingCallAfterDeath) {
  StrictMock<MockFoo>* const strict_foo = new StrictMock<MockFoo>;

  ON_CALL(*strict_foo, DoThis())
      .WillByDefault(Invoke(strict_foo, &MockFoo::Delete));

  strict_foo->DoThis();
}





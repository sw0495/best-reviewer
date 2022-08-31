
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

class Bar {};

class Foo {
public:
    virtual ~Foo() {};
    virtual int GetSize() const {return 1;} //const = 0;
    virtual bool Process(Bar elem, int count) = 0;

    virtual string Describe(const char* name) {return name;}
    //string Describe(int type) {return "";}    
};

class MockFoo : public Foo {
public:
  MOCK_METHOD(int, GetSize, (), (const, override));
  MOCK_METHOD(bool, Process, (Bar elem, int count), (override));
  MOCK_METHOD(string, Describe, (const char* name), (override));
  //MOCK_METHOD(string, Describe, (int type)); 
};

TEST(TestForMyClass, TestGetSize)
{
    MockFoo obj1;
    EXPECT_CALL(obj1, GetSize)
        .Times(1);    
        
    EXPECT_EQ(0, obj1.GetSize());

    EXPECT_CALL(obj1, GetSize())
        .Times(1)
        .WillOnce(Return(0))
        .WillOnce(Return(2))
        .WillRepeatedly(Return(3));
    EXPECT_EQ(0, obj1.GetSize());    

}


TEST(TestForMyClass, TestDescribe)
{
    MockFoo obj1;
    //EXPECT_CALL(obj1, Describe(1))
    //    .Times(AtLeast(0));  

    EXPECT_CALL(obj1, Describe("123"))
        .Times(AtLeast(1));  

    EXPECT_CALL(obj1, Describe(::testing::_))
        .Times(0); 

    EXPECT_CALL(obj1, Describe)
        .Times(0); 
}

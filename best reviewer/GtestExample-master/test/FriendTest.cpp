#include <gtest/gtest.h>

namespace internal {
class Foo {
    friend class FooTest;
    FRIEND_TEST(FooTest, Bar);
    FRIEND_TEST(FooTest, Baz);    
private:
    int Bar(void* x){
        return 1;
    }

    int Baz(void* x){
        return 2;
    }
};

class FooTest : public testing::Test {    
protected:
    Foo foo;
};

TEST_F(FooTest, Bar) { 
    EXPECT_EQ(foo.Bar(NULL), 1); 
}
TEST_F(FooTest, Baz) {
    EXPECT_EQ(foo.Baz(NULL), 1); 
}

}
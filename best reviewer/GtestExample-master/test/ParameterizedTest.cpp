
#include <gtest/gtest.h>

class Foo
{
public:
    bool Blah(const char *arg) {
        
        if (strcmp(arg, "cat")==0 || strcmp(arg, "moe")==0) {
            //std::cout << "true=" << arg << std::endl;
            return true;
        }

        //std::cout << "false=" << arg << std::endl;
        return false;
    }

};

class FooTest :
    public testing::TestWithParam<const char*> {
public:
        
    void SetUp() override {

    }

    Foo foo;
};

namespace{

INSTANTIATE_TEST_SUITE_P(InstantiationName,
                    FooTest,
                    testing::Values("meeny", "miny", "moe"));


TEST_P(FooTest, DoesBlah) {
    EXPECT_TRUE(foo.Blah(GetParam()));  
}


const char* pets[] = {"cat", "dog"};
INSTANTIATE_TEST_SUITE_P(AnotherInstantiationName, FooTest,
                    testing::ValuesIn(pets));

TEST_P(FooTest, HasBlahBlah) {
    EXPECT_TRUE(foo.Blah(GetParam()));  
}
    

}




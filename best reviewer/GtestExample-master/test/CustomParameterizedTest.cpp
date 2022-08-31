#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>

namespace {

class CustomFunctorNamingTest : public testing::TestWithParam<std::string> {};
TEST_P(CustomFunctorNamingTest, CustomTestNames) {}

struct CustomParamNameFunctor {
  std::string operator()(const ::testing::TestParamInfo<std::string>& info) {
    return info.param;
  }
};

INSTANTIATE_TEST_CASE_P(CustomParamNameFunctor,
                        CustomFunctorNamingTest,
                        testing::Values(std::string("FunctorName")),
                        CustomParamNameFunctor());

INSTANTIATE_TEST_CASE_P(AllAllowedCharacters,
                        CustomFunctorNamingTest,
                        testing::Values("test1",
                               "test2",
                               "test3"),
                        CustomParamNameFunctor());


enum class MyType { MY_FOO = 0, MY_BAR = 1 };
class MyTestSuite  : public testing::TestWithParam< std::tuple<MyType, std::string> > {
};

TEST_P(MyTestSuite , MyTest) {
    GetParam();
    //std::cout << std::get<1>(GetParam()) << std::endl;
}

/*
struct CustomParamNameFunctor2 {

  std::string operator()(const testing::TestParamInfo<MyTestSuite::ParamType>& info) {
    //return std::get<1>(info.param);
    std::string name = std::get<0>(info.param) == MyType::MY_FOO ? "Foo_" : "Bar_";
                                 //+ std::get<1>(info.param);
    return name + std::get<1>(info.param);
  }
};
*/

INSTANTIATE_TEST_SUITE_P(MeaningfulTestParameters, MyTestSuite,
                        testing::Combine(testing::Values(MyType::MY_FOO, MyType::MY_BAR), testing::Values("1","2")),
                        [](const testing::TestParamInfo<MyTestSuite::ParamType>& info) {
                            std::string name = std::get<0>(info.param) == MyType::MY_FOO ? "Foo_" : "Bar_";
                            return name + std::get<1>(info.param);
                         });

}  // namespace

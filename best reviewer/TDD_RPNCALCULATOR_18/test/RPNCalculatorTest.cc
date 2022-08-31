#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "iostream"
#include "../src/RPNCalculator.h"

TEST(RPNCalculator, frameworkCheckTest)
{
    RPNCalculator *sc;
    ASSERT_NE(sc, nullptr);
}

TEST(RPNCalculator, addTest)
{
    RPNCalculator sc;
    vector<string> addString = {"1", "2", "+"};
    ASSERT_EQ(3, sc.calculator(addString));
}

TEST(RPNCalculator, subtractTest)
{
    RPNCalculator sc;
    vector<string> subtractString = {"1", "2", "-"};
    ASSERT_EQ(-1, sc.calculator(subtractString));
}

TEST(RPNCalculator, multiplyTest)
{
    RPNCalculator sc;
    vector<string> multiplyString = {"2", "3", "*"};
    ASSERT_EQ(6, sc.calculator(multiplyString));
}

TEST(RPNCalculator, deviedTest)
{
    RPNCalculator sc;
    vector<string> deviedString = {"20", "5", "/"};
    ASSERT_EQ(4, sc.calculator(deviedString));
}

TEST(RPNCalculator, deviedTestByZeroException)
{
    RPNCalculator sc;
    vector<string> deviedString = {"20", "0", "/"};
    ASSERT_THROW(sc.calculator(deviedString), string);
}

TEST(RPNCalculator, addAndMultiplyTest)
{
    RPNCalculator sc;
    vector<string> addAndMultiplyTwoTimestString = {"4", "2", "+", "3", "*"};
    ASSERT_EQ(18, sc.calculator(addAndMultiplyTwoTimestString));

    vector<string> addAndMultiplyThreeTimesString = {"3", "5", "8", "*", "7", "+", "*"};
    ASSERT_EQ(141, sc.calculator(addAndMultiplyThreeTimesString));
}

TEST(RPNCalculator, sqrtTest)
{
    RPNCalculator sc;
    vector<string> sqrtString = {"9", "SQRT"};
    ASSERT_EQ(3, sc.calculator(sqrtString));
}

 TEST(RPNCalculator, maxTest)
{
    RPNCalculator sc;
    vector<string> maxString1 = {"4", "5", "MAX", "1", "2", "MAX"};
    ASSERT_EQ(5, sc.calculator(maxString1));

    vector<string> maxString2 = {"5", "3", "9", "2", "4", "1", "MAX"};
    ASSERT_EQ(9, sc.calculator(maxString2));
}
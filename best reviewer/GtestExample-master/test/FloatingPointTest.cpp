#include <gtest/gtest.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

namespace {

// Tests Assert_Pred_Test().

TEST(SampleTestCase, CompareTwoValue) {
    //EXPECT_EQ(8.000001, pow(2.0, 3.0)); 
    //EXPECT_FLOAT_EQ(8.0001, pow(2.0, 3.0));
    EXPECT_NEAR(8.0001, pow(2.0, 3.0), 0.1);
}

TEST(SampleTestCase, PredValue) {
    EXPECT_PRED_FORMAT2(testing::FloatLE, 7.9, pow(2.0, 3.0));
    EXPECT_PRED_FORMAT2(testing::FloatLE, 8.0, pow(2.0, 3.0));
    //EXPECT_PRED_FORMAT2(testing::FloatLE, 8.1, pow(2.0, 3.0));
    EXPECT_PRED_FORMAT2(testing::DoubleLE, 8.0, pow(2.0, 3.0));
}

}
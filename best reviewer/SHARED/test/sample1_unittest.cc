

#include <limits.h>
#include "sample1.h"
#include <gtest/gtest.h>

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;



namespace {



// Tests factorial of 0.
TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, Factorial(0));
}


}  // namespace



int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

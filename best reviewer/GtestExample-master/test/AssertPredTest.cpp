
#include <gtest/gtest.h>

#include "../src/Source.h"
namespace {


// Tests Assert_Pred_Test().

TEST(MutuallyPrimeTest, MutuallyPrime) {

    const int a = 3;
    const int b = 4;
    const int c = 5;

    EXPECT_PRED2(MutuallyPrime, a, b);    //성공
    EXPECT_PRED2(MutuallyPrime, b, c);    //실패
}

TEST(AssertPredTest, IsPositive) {
    //EXPECT_PRED1(IsPositive, 5);
    EXPECT_PRED1(static_cast<bool (*)(int)>(IsPositive), 5);

    ASSERT_PRED1(IsNegative<int>, -5);
    //ASSERT_PRED2(GreaterThan<int, int>, 5, 0);
    ASSERT_PRED2((GreaterThan<int, int>), 5, 0);
    
}

testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0)
    return testing::AssertionSuccess() << n << " is even"; 
  else
    return testing::AssertionFailure() << n << " is odd";
}

TEST(AssertionResultTest, IsEven) {
    EXPECT_TRUE(IsEven(4));   
    EXPECT_FALSE(IsEven(6));  
}


int SmallestPrimeCommonDivisor(int m, int n) { return 1; }

// A predicate-formatter for asserting that two integers are mutually prime.
::testing::AssertionResult AssertMutuallyPrime(const char* m_expr,
                                               const char* n_expr,
                                               int m,
                                               int n) {
    if (MutuallyPrime(m, n)) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << m_expr << " and " << n_expr
      << " (" << m << " and " << n << ") are not mutually prime, "
      << "as they have a common divisor " << SmallestPrimeCommonDivisor(m, n);
}

TEST(AssertionResultTest, AssertMutuallyPrime) {
    const int a = 3;
    const int b = 4;
    const int c = 8;

    EXPECT_PRED_FORMAT2(AssertMutuallyPrime, b, c);
}

}
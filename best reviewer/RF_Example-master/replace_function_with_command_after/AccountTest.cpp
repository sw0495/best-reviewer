#include <gtest/gtest.h>
#include "Account.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;
 
TEST(AccountTest, test) {
    ASSERT_EQ(15396520, Account().gamma(1000, 2, 2200));

    ASSERT_EQ(14696660, Account().gamma(1000, 2, 2100));

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#include <gtest/gtest.h>
#include "Product.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;
 
TEST(blaTest, test1) {
    
    ASSERT_EQ(1900, Product(4, 500).getPrice());
    
    ASSERT_EQ(980, Product(4,250).getPrice());

}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
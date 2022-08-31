#include <gtest/gtest.h>
#include "Order.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;

TEST(ZipCodeTest, testZipCode) {
    Order order;
    shared_ptr<Customer> customer = make_shared<Customer>("Kent");
    shared_ptr<Address> address = make_shared<Address>("06366");
    customer->setAddress(address);
    order.setCustomer(customer);
    ASSERT_EQ("06366", order.getCustomer()->getAddress()->getZipCode());
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
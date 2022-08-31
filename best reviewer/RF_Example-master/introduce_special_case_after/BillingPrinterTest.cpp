#include <gtest/gtest.h>
#include "BillingPrinter.h"
#include "Company.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;


TEST(BuildingPrinterTest, testBilling) {
    Company company;
    shared_ptr<Customer> customer = make_shared<Customer>("Johnny");
    shared_ptr<BillingPlan> plan = make_shared<BillingPlan>();
    shared_ptr<PaymentHistory> history = make_shared<PaymentHistory>();
    history->setWeeksDelinquentInLastYear(30);
    customer->setPaymentHistory(history);    
    
    customer->setBillingPlan(plan);
    company.setCustomer(customer);
    
    EXPECT_EQ(BillInfo("Johnny", plan, 30)
                , BillingPrinter::billing(company.getCustomer()));

}

TEST(BuildingPrinterTest, OccupantTest) {
    Company company;
    shared_ptr<Customer> customer = make_shared<Customer>("Johnny");
    shared_ptr<BillingPlan> plan = make_shared<BillingPlan>();
    shared_ptr<PaymentHistory> history = make_shared<PaymentHistory>();
    history->setWeeksDelinquentInLastYear(30);
    customer->setPaymentHistory(history);    
    
    customer->setBillingPlan(plan);
    
    EXPECT_EQ(BillInfo("Occupant", BillingPlan::basic(), 0)
                , BillingPrinter::billing(company.getCustomer()));
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


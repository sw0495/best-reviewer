#include "BillingPrinter.h"
//#include "BillingPlan.h"

BillInfo BillingPrinter::billing(shared_ptr<Customer> customer) {
    
    string customerName = customer->getName();
    shared_ptr<BillingPlan> plan = customer->getPlan();
    int weeksDelinquent = customer->getHistory()->getWeeksDelinquentInLastYear();

    return BillInfo(customerName, plan, weeksDelinquent);

    // string customerName;
    // if (customer == nullptr) {
    //     customerName = "Occupant";
    // }
    // else {
    //     customerName = customer->getName();
    // }

    // shared_ptr<BillingPlan> plan;
    // if (customer == nullptr) {
    //     plan = BillingPlan::basic();
    // }
    // else {
    //     plan = customer->getPlan();
    // }

    // int weeksDelinquent;
    // if (customer == nullptr) {
    //     weeksDelinquent = 0;
    // }
    // else {
    //     weeksDelinquent = customer->getHistory()->getWeeksDelinquentInLastYear();
    // }

    // return BillInfo(customerName, plan, weeksDelinquent);
    
}

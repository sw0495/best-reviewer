#ifndef BILLINGPLAN_H
#define BILLINGPLAN_H

#include <memory>

using namespace std;
class BillingPlan {
public:
    static shared_ptr<BillingPlan> basic() {
        return make_shared<BillingPlan>(); 
    }
};

#endif

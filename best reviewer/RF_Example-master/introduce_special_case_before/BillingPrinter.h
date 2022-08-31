#ifndef BILLINGPRINTER_H
#define BILLINGPRINTER_H

#include <memory>

#include "BillInfo.h"
#include "Customer.h"

using namespace std;

class BillingPrinter {
public:
    
    static BillInfo billing(shared_ptr<Customer>);

};

#endif
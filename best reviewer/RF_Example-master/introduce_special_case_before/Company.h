#ifndef COMPANY_H
#define COMPANY_H

#include "Customer.h"
#include <memory>

class Company {
public:
    
    shared_ptr<Customer> getCustomer() {
        return m_customer;
    };
    
    void setCustomer(shared_ptr<Customer> customer) {
        m_customer = customer;
    };

private:
    shared_ptr<Customer> m_customer;
    
};

#endif
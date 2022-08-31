#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Address.h"
#include <memory>

class Customer {
public:
    Customer(string name) : m_name(name) {}

    std::shared_ptr<Address> getAddress() {
        return m_address;
    }

    void setAddress(std::shared_ptr<Address> address) {
        m_address = address;
    } 

private:
    string m_name;
    shared_ptr<Address> m_address;    
};

#endif

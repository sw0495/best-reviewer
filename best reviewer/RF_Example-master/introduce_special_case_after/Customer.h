#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BillingPlan.h"
#include "PaymentHistory.h"
#include <iostream>
#include <memory>

using namespace std;

class Customer {
public:
    Customer(string);    
    string getName();
    shared_ptr<BillingPlan> getPlan();
    shared_ptr<PaymentHistory> getHistory();
    void setBillingPlan(shared_ptr<BillingPlan>);
    void setPaymentHistory(shared_ptr<PaymentHistory>);

protected:
    string m_name;
    shared_ptr<BillingPlan> m_billingPlan;
    shared_ptr<PaymentHistory> m_paymentHistory;
};


inline Customer::Customer(string name) : m_name(name) {}

inline string Customer::getName() { return m_name; }

inline shared_ptr<BillingPlan> Customer::getPlan() { return m_billingPlan; }

inline shared_ptr<PaymentHistory> Customer::getHistory() { 
    // if (m_paymentHistory==nullptr) {
    //     return make_shared<NullPaymentHistory>();
    // }
    return m_paymentHistory; 
}

inline void Customer::setBillingPlan(shared_ptr<BillingPlan> billingPlan) {
    m_billingPlan = billingPlan;
}

inline void Customer::setPaymentHistory(shared_ptr<PaymentHistory> paymentHistory) {
    m_paymentHistory = paymentHistory;
}

class UnknownCustomer : public Customer {
public:
    UnknownCustomer() : Customer("Occupant") {
        m_billingPlan = BillingPlan::basic();
        m_paymentHistory = make_shared<PaymentHistory>();
        m_paymentHistory -> setWeeksDelinquentInLastYear(0);
    }

    // inline string Customer::getName() { return "Occupant"; }
    
};



#endif


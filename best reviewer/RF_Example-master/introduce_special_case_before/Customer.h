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

private:
    string m_name;
    shared_ptr<BillingPlan> m_billingPlan;
    shared_ptr<PaymentHistory> m_paymentHistory;
};


inline Customer::Customer(string name) : m_name(name) {}

inline string Customer::getName() { return m_name; }

inline shared_ptr<BillingPlan> Customer::getPlan() { return m_billingPlan; }

inline shared_ptr<PaymentHistory> Customer::getHistory() { return m_paymentHistory; }

inline void Customer::setBillingPlan(shared_ptr<BillingPlan> billingPlan) {
    m_billingPlan = billingPlan;
}

inline void Customer::setPaymentHistory(shared_ptr<PaymentHistory> paymentHistory) {
    m_paymentHistory = paymentHistory;
}

#endif


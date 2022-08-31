#ifndef BILLINFO_H
#define BILLINFO_H

#include "BillingPlan.h"
#include <iostream>
#include <memory>

using namespace std;

class BillInfo {
public:
    BillInfo(string name, shared_ptr<BillingPlan> plan, int weeksDelinquent) 
        : m_name(name), m_plan(plan), m_weeksDelinquent(weeksDelinquent) 
    {
    }
    
    bool operator==(const BillInfo& rhs) const {
        cout << m_name << m_weeksDelinquent << rhs.m_name << rhs.m_weeksDelinquent;
        return (m_name == rhs.m_name) //&& (m_plan == rhs.m_plan)
            && (m_weeksDelinquent == rhs.m_weeksDelinquent);
    }


private:
    string m_name;
    shared_ptr<BillingPlan> m_plan;
    int m_weeksDelinquent;
};

#endif
#include <memory>
#include <iostream>
#include "Employee.h"

Employee::Employee(int arg)
{        
    m_type = arg;
};


int Employee::payAmount() {
    switch (m_type) {
        case ENGINEER:
            return m_monthlySalary;
        case SALESMAN:
            return m_monthlySalary + m_commission;
        case MANAGER:
            return m_monthlySalary + m_bonus;
        default:
            throw TypeException();
    }    
}



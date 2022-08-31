#include <memory>
#include <iostream>
#include "EmployeeType.h"
#include "Employee.h"

Employee::Employee(int arg)
{        
    // m_type = arg;
    setType(arg);
};

int Employee::getType() {
    return m_type -> getCode();
    // return 0;
}

void Employee::setType(int type) {
    m_type = EmployeeType::create(type);
}


int Employee::payAmount() {
    return m_type -> payAmount(*this);

    // switch (getType()) {
    //     case ENGINEER:
    //         return m_monthlySalary;
    //     case SALESMAN:
    //         return m_monthlySalary + m_commission;
    //     case MANAGER:
    //         return m_monthlySalary + m_bonus;
    //     default:
    //         throw TypeException();
    // }    
}





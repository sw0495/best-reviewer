#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// #include "EmployeeType.h"
class EmployeeType;
class Employee {
public:

    static const int ENGINEER = 0;
    static const int SALESMAN = 1;
    static const int MANAGER = 2;
    
    Employee(int);      
    
    int m_monthlySalary;
    int m_commission;
    int m_bonus;
    int payAmount();
private:
    std::shared_ptr<EmployeeType> m_type;   
    int getType();
    void setType(int);
};


class TypeException : public std::exception{
public:
    virtual const char* what() {
        return "employee type mismatching";
    } 
};

#endif







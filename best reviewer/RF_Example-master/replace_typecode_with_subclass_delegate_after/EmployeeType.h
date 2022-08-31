#ifndef EMPLOYEETYPE_H
#define EMPLOYEETYPE_H

#include <memory>
#include "Employee.h"

class EmployeeType {
public:

    static const int ENGINEER = 0;
    static const int SALESMAN = 1;
    static const int MANAGER = 2;

    static std::shared_ptr<EmployeeType> create(int);
    virtual int getCode()=0;
    virtual int payAmount(Employee&)=0;
};

class Engineer : public EmployeeType {
public:
    int getCode() override {
        return ENGINEER;
    }
    int payAmount(Employee& employee) override {
        return employee.m_monthlySalary;
    }
};

class Salesman : public EmployeeType {
public:
    int getCode() override {
        return SALESMAN;
    }
    int payAmount(Employee& employee) override {
        return employee.m_monthlySalary + employee.m_commission;
    }
};

class Manager : public EmployeeType {
public:
    int getCode() override {
        return MANAGER;
    }
    int payAmount(Employee& employee) override {
        return employee.m_monthlySalary + employee.m_bonus;
    }
};

#endif
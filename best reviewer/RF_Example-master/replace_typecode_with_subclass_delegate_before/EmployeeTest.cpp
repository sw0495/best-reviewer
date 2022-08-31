#include <gtest/gtest.h>
#include "Employee.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;

Employee createEmployee(int type) {
    const int MONTHLY_SALARY = 2000;
    const int COMMISSION = 500;
    const int BONUS = 1000;

    Employee e(type);
    e.m_monthlySalary = MONTHLY_SALARY;
    e.m_commission = COMMISSION;
    e.m_bonus = BONUS;
    return e;
}

TEST(employeeTest, testEngineerSalary) {

    //testEngineerSalary
    Employee e = createEmployee(Employee::ENGINEER);
    ASSERT_EQ(2000, e.payAmount());    
}

TEST(employeeTest, testSalesmanSalary) {
    Employee e = createEmployee(Employee::SALESMAN);
    ASSERT_EQ(2500, e.payAmount());
}

TEST(employeeTest, testManagerSalary) {
    Employee e = createEmployee(Employee::MANAGER);
    ASSERT_EQ(3000, e.payAmount());
}

TEST(employeeTest, testWrongEmployeeType) {
    Employee e = createEmployee(100);
    ASSERT_THROW(e.payAmount(), TypeException);    
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
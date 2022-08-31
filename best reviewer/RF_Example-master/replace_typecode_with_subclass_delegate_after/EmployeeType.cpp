#include "EmployeeType.h"

std::shared_ptr<EmployeeType> EmployeeType::create(int type) {
    if (type==EmployeeType::ENGINEER) 
        return std::make_shared<Engineer>();

    if (type==EmployeeType::SALESMAN) 
        return std::make_shared<Salesman>();

    if (type==EmployeeType::MANAGER) 
        return std::make_shared<Manager>();

    throw TypeException();


}
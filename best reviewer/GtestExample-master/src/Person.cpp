#include "Person.h"

using namespace std;

Person::Person(const string &firstName, const string &lastName){
    m_firstName = firstName;
    m_lastName = lastName;
}

const string &Person::getFirstName(){
    return m_firstName;
}
const string &Person::getLastName(){
    return m_lastName;
}
const string &Person::getFullName(){
    return m_firstName + " " + m_lastName;
}

void Person::setAge(int age){
    m_age = age;
}
int Person::getAge(){
    return m_age;
}

bool Person::isAdult(int age){
    return m_age >= ADULT_AGE;
}


#include <iostream>

class Person {
    const static int ADULT_AGE = 19;
public:
    Person::Person(const std::string &, const std::string &);

    const std::string &Person::getFirstName();
    const std::string &Person::getLastName();
    const std::string &Person::getFullName();

    void Person::setAge(int);
    int Person::getAge();

    bool Person::isAdult(int);

private:
    std::string m_firstName;
    std::string m_lastName;
    int m_age;

};
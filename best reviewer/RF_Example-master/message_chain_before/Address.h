#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;

class Address {
public:
    Address(string zipCode) : m_zipCode(zipCode) {
    }
        
    string getZipCode() {
        return m_zipCode;
    }

private:
    string m_zipCode;
   
};

#endif
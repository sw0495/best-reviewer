#ifndef INVOICE_H
#define INVOICE_H

#include "Performance.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Invoice {
public:
    Invoice(string customer, vector<Performance> performances) 
        : customer_(customer), performances_(performances) {
    }
    
    string customer_;
    vector<Performance> performances_;   
};

#endif
#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <vector>
#include <string>
#include "Order.h"

using namespace std;

class Printer {
public:
    
    vector<Order> orders;
    string PrintOwing(string);

private:    

};

#endif
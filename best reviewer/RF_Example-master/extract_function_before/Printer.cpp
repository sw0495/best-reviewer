#include <iostream>
#include "Printer.h"
#include "Order.h"

using namespace std;

string Printer::PrintOwing(string name) 
{
    string result;
    double outstanding = 0.0;
    
    //printBanner
    result.append("********************************\n");
    result.append("******   Customer totals   *****\n");
    result.append("********************************\n");    
    
    //calculate outstanding
    for (auto order : orders) {
        outstanding += order.getAmount();
    }

    //print details
    result.append("name: " + name + "\n");
    result.append("amount: " + to_string(static_cast<int>(outstanding)));    
    
    return result;    
}





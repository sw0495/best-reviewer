#include <iostream>
#include "Printer.h"
#include "Order.h"

using namespace std;

string Printer::PrintOwing(string name) 
{
    string result;
    result.append(printBanner());
    double outstanding = calculatorOutstanding();
    result.append(printDetails(name, outstanding));
    
    return result;    
}

string Printer::printBanner() {
    string result;

    result.append("********************************\n");
    result.append("******   Customer totals   *****\n");
    result.append("********************************\n");    

    return result;
}


string Printer::printDetails(const string& name, const double outstanding) {
    string result;

    result.append("name: " + name + "\n");
    result.append("amount: " + to_string(static_cast<int>(outstanding)));    
    
    return result;
} 

double Printer::calculatorOutstanding() {
    double outstanding = 0.0;
    // vector<Order>::iterator it;
    
    // for (it = orders.begin(); it != orders.end(); it++) {
    //     outstanding += it->getAmount();
    // };

    for (auto order : orders) {
        outstanding += order.getAmount();
    }

    return outstanding;    
}






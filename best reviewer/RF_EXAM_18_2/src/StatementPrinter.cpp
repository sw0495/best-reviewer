#include "Performance.h"
#include "StatementPrinter.h"
#include <sstream>
#include <cmath>
#include <map>
#include <iostream>
#include "Play.h"

using namespace std;

std::string StatementPrinter::print(Invoice invoice, map<string, shared_ptr<Play>> plays) {
    float totalAmount = 0;
    int volumeCredits = 0;
    std::ostringstream result;
    result << "Statement for " << invoice.customer_ << "\n";
    
    for (auto& perf : invoice.performances_) {
        shared_ptr<Play> play = plays[perf.playID_];
        
        float thisAmount = play->payAmount(perf.audience_);
        
        volumeCredits += std::max(perf.audience_ - 30, 0);
        
        if (play->getType() == "comedy") 
            volumeCredits += floor(perf.audience_ / 5);

        result << "  " << play->getName() << ": $" << presentPrice(thisAmount/100) << 
            " (" << perf.audience_ << " seats)\n";
        
        totalAmount += thisAmount;
        
    }
    result << "Amount owed is $" << presentPrice(totalAmount / 100.0f) << "\n";
    result << "You earned " << volumeCredits << " credits\n";
    
    return result.str();

}

string StatementPrinter::presentPrice(double price)
{
    char buf[20];
    snprintf(buf, 20, "%.2f", price);
    return string(buf);
}

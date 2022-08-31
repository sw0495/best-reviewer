#ifndef _TEXTPRINTER_H_
#define _TEXTPRINTER_H_
#include <sstream>
#include <vector>
#include <string>
#include "Printer.h"

class TextPrinter : public Printer{
public:
    void printHead(std::ostringstream & result, std::string name) {
        result << "Rental Record for " << name << "\n";
    }

    void printtail(std::ostringstream & result, std::string title, double amount) {
        result << "\t" << title << "\t"
        << amount << std::endl;
    }

    void printfooter(std::ostringstream & result, double totalAmount) {
        result << "Amount owed is " << totalAmount << "\n";
        result << "You earned " << getFrequentRenterPoints()
            << " frequent renter points";
    }

};

#endif
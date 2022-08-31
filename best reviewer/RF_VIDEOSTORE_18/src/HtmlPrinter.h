#ifndef _HTMLPRINTER_H_
#define _HTMLPRINTER_H_
#include <sstream>
#include <vector>
#include <string>
#include "Printer.h"

class HtmlPrinter : public Printer{
public:
    void printHead(std::ostringstream & result, std::string name) {
        result << "<H1>Rentals for <EM>" << name << "</EM></H1><P>\n";
    }

    void printtail(std::ostringstream & result, std::string title, double amount) {
        result << "&nbsp;&nbsp;&nbsp;&nbsp;" << title << " : "
                << amount << "<BR>\n";
    }

    void printfooter(std::ostringstream & result, double totalAmount) {
        result << "<P>Amount owed is <EM>" << totalAmount << "</EM><P>\n";
        result << "You earned <EM>" << getFrequentRenterPoints()
                << "</EM> frequent renter points<P>";
    }

};

#endif
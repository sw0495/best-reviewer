#ifndef STATEMENTPRINTER_H
#define STATEMENTPRINTER_H

#include "Invoice.h"
#include "Play.h"

#include <map>
#include <memory>

class StatementPrinter {
public:
    std::string print(Invoice, std::map<string, std::shared_ptr<Play>>);
private:
    string presentPrice(double price);
};


#endif
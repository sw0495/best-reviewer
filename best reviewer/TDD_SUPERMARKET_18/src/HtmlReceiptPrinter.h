#ifndef _HTMLRECEIPTPRINTER_H_
#define _HTMLRECEIPTPRINTER_H_
#include <string>
#include "Receipt.h"
#include "Printer.h"

class HtmlReceiptPrinter : public Printer {
public:
	string printReceipt(Receipt&) override;
	string htmlReceiptHead();
	string htmlReceiptEnding();
	string presentReceiptItem(ReceiptItem&) override; 
	string presentTotal(Receipt&) override; 
	string formatLineWithWhitespace(string&, string&) override;	
};

#endif

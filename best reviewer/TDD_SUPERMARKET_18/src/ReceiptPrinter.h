#ifndef _RECEIPTPRINTER_H_
#define _RECEIPTPRINTER_H_
#include <string>
#include "Receipt.h"
#include "Printer.h"

class ReceiptPrinter : public Printer {
public:
    string printReceipt(Receipt& receipt) override;
	ReceiptPrinter() :columns(40) {}
	ReceiptPrinter(int columns) :columns(columns) {}
	string presentReceiptItem(ReceiptItem& item) override;
	string presentTotal(Receipt& receipt) override;
	string formatLineWithWhitespace(string& name, string& value) override;
    
private:
	int columns;
};

#endif

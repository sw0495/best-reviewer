#ifndef _PRINTER_H_
#define _PRINTER_H_
#include <string>
#include "Receipt.h"

class Printer {
public:
void printReceiptBody(string& result, Receipt& receipt)
{
        for (auto & item : receipt.getReceiptItems()) {
        string receiptItem = presentReceiptItem(item);
        result.append(receiptItem);
    }
    for (auto & discount : receipt.getDiscounts()) {
        string discountPresentation = presentDiscount(discount);
        result.append(discountPresentation);
    }
}

string presentDiscount(Discount& discount)
{
    string name = discount.getDescription() + "(" + discount.getProduct().getName() + ")";
    string value = "-" + presentPrice(discount.getDiscountAmount());

    return formatLineWithWhitespace(name, value);
}

string presentPrice(double price)
{
    char buf[20];
    snprintf(buf, 20, "%.2f", price);
    return string(buf);
}

string presentQuantity(ReceiptItem& item)
{
    char buf[20];    
    if (ProductUnit::Each == item.getProduct().getUnit())
        snprintf(buf, 20, "%x", (int)item.getQuantity());
    else
        snprintf(buf, 20, "%.3f", item.getQuantity());
    return string(buf);
}

virtual string printReceipt(Receipt& receipt) = 0;
virtual string presentReceiptItem(ReceiptItem&) = 0; 
virtual string presentTotal(Receipt&) = 0;
virtual string formatLineWithWhitespace(string& name, string& value) = 0;

};

#endif
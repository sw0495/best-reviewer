#include "ReceiptPrinter.h"
#include <sstream>

string ReceiptPrinter::printReceipt(Receipt& receipt)
{
    string result;

    printReceiptBody(result, receipt);

    result.append("\n");
    result.append(presentTotal(receipt));
    return result;
}

string ReceiptPrinter::presentReceiptItem(ReceiptItem& item)
{
    string totalPricePresentation = presentPrice(item.getTotalPrice());
    string name = item.getProduct().getName();

    string line = formatLineWithWhitespace(name, totalPricePresentation);

    if (item.getQuantity() != 1) {
        line += "  " + presentPrice(item.getPrice()) + " * " + presentQuantity(item) + "\n";
    }
    return line;
}

string ReceiptPrinter::presentTotal(Receipt& receipt)
{
    string name = "Total: ";
    string value = presentPrice(receipt.getTotalPrice());
    return formatLineWithWhitespace(name, value);
}

string ReceiptPrinter::formatLineWithWhitespace(string& name, string& value)
{
    string line;
    line.append(name);
    int whitespaceSize = columns - name.length() - value.length();
    for (int i = 0; i < whitespaceSize; i++) {
        line.append(" ");
    }
    line.append(value);
    line.append("\n");
    return line;
}


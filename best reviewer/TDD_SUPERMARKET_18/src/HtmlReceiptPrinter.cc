#include "HtmlReceiptPrinter.h"
#include <sstream>

string HtmlReceiptPrinter::printReceipt(Receipt& receipt) 
{
    string result;     
    result.append(htmlReceiptHead());
    
    printReceiptBody(result, receipt);

    result.append(presentTotal(receipt));
    result.append(htmlReceiptEnding());    
    return result;
}

string HtmlReceiptPrinter::htmlReceiptHead() 
{
    return "<table>\n";
}

string HtmlReceiptPrinter::htmlReceiptEnding() 
{
    return "</table>\n";
}

string HtmlReceiptPrinter::presentReceiptItem(ReceiptItem& item) 
{
    string totalPricePresentation = presentPrice(item.getTotalPrice());
    string name = item.getProduct().getName();

    string line = formatLineWithWhitespace(name, totalPricePresentation);

    if (item.getQuantity() != 1) {
        line += "<tr><td colspan=2>" + presentPrice(item.getPrice()) + " * " + presentQuantity(item) + "</td></tr>\n";
    }
    return line;
}

string HtmlReceiptPrinter::presentTotal(Receipt& receipt) 
{
    string name = "<b>Total: ";
    string value = presentPrice(receipt.getTotalPrice());
    return formatLineWithWhitespace(name, value) + "<tr><td colspan=2>&nbsp;</td></tr>\n";
}

string HtmlReceiptPrinter::formatLineWithWhitespace(string& name, string& value) 
{
    string line;
    line.append("<tr><td>");
    line.append(name);
    line.append("</td><td>");
    line.append(value);
    line.append("</td></tr>\n");    
    return line;
}


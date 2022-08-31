// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"
#include "TextPrinter.h"
#include "HtmlPrinter.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  std::ostringstream result;
  TextPrinter textprinter;
  textprinter.printHead(result, getName());

  for ( ; iter != iter_end; ++iter ) {

    Rental each = *iter;
    double thisAmount = textprinter.CalculateAmount(each);

    textprinter.printtail(result, each.getMovie().getTitle(), thisAmount);
    totalAmount += thisAmount;
  }

   textprinter.printfooter(result, totalAmount);

  return result.str();
}

std::string Customer::htmlstatement()
{
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  std::ostringstream result;
  HtmlPrinter htmlprinter;
  htmlprinter.printHead(result, getName());

  for ( ; iter != iter_end; ++iter ) {

    Rental each = *iter;
    double thisAmount = htmlprinter.CalculateAmount(each);

    htmlprinter.printtail(result, each.getMovie().getTitle(), thisAmount);
    totalAmount += thisAmount;
  }

   htmlprinter.printfooter(result, totalAmount);

  return result.str();
}
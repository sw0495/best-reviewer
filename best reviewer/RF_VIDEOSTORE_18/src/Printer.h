#ifndef _PRINTER_H_
#define _PRINTER_H_
#include <sstream>
#include <vector>
#include <string>
#include "Rental.h"

class Printer {
public:
    Printer():frequentRenterPoints(0) {}

    double CalculateAmount(Rental& rental) {
        Movie movie = rental.getMovie();
        double thisAmount = movie.payAmount(rental.getDaysRented());

        frequentRenterPoints++;

        if ( ( rental.getMovie().getPriceCode() == Movie::NEW_RELEASE )
        && rental.getDaysRented() > 1 ) frequentRenterPoints++;
            
        if ( rental.getMovie().getPriceCode() == Movie::BESTSELLER )
        frequentRenterPoints = frequentRenterPoints + 5;  

        return thisAmount;
    } 

    int getFrequentRenterPoints() {
      return frequentRenterPoints;
    }

    virtual void printHead(std::ostringstream &, std::string) = 0;
    virtual void printtail(std::ostringstream &, std::string, double) = 0;
    virtual void printfooter(std::ostringstream & result, double totalAmount) = 0;

private:
    int frequentRenterPoints;
};
#endif


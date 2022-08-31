#ifndef MOVIETYPE_H
#define MOVIETYPE_H
#include <string>
#include <memory>
#include "Rental.h"

class MovieType {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;
  static const int BESTSELLER = 3;
  static const int UNKNOWN = 100;

  static std::shared_ptr<MovieType> create(int type); 

  void setTitle(std::string); 
  std::string getTitle();

  virtual int getPriceCode() = 0;
  virtual double payAmount(int) = 0;

  std::string movieTitle;
  int moviePriceCode;
};

void MovieType::setTitle(std::string title) {
    movieTitle = title;
}

std::string MovieType::getTitle() {
    return movieTitle;
}

class Childrens : public MovieType {
public:
    int getPriceCode() override {
        return CHILDRENS;
    }

    double payAmount(int DaysRented) override {
        double thisAmount = 0.;
        thisAmount += 1.5;
        if ( DaysRented > 3 )
          thisAmount += ( DaysRented - 3 ) * 1.5;
        return thisAmount;
    }

};

class Regular : public MovieType {
public:
    int getPriceCode() override {
        return REGULAR;
    }

    double payAmount(int DaysRented) override {
        double thisAmount = 0.;
        thisAmount += 2.;
        if ( DaysRented > 2 )
          thisAmount += ( DaysRented - 2 ) * 1.5 ;
        return thisAmount;
    }

};

class New_Release : public MovieType {
public:
    int getPriceCode() override {
        return NEW_RELEASE;
    }

    double payAmount(int DaysRented) override {
        double thisAmount = 0.;
        thisAmount += DaysRented * 3;
        return thisAmount;
    }

};

class UnKnown : public MovieType {
public:
    int getPriceCode() override {
        return UNKNOWN;
    }

    double payAmount(int DaysRented) override {
        double thisAmount = 0.;
        thisAmount += DaysRented * 2;
        return thisAmount;
    }

};

class BestSeller : public MovieType {
public:
    int getPriceCode() override {
        return BESTSELLER;
    }

    double payAmount(int DaysRented) override {
        double thisAmount = 0.;
        thisAmount += 5.;
        if ( DaysRented > 2 )
          thisAmount += ( DaysRented - 2 ) * 7.5 ;
        return thisAmount;
    }

};

std::shared_ptr<MovieType> MovieType::create(int type) {
    if (type == MovieType::CHILDRENS)
        return std::make_shared<Childrens>();   
    else if (type==MovieType::REGULAR) 
        return std::make_shared<Regular>();
    else if (type==MovieType::NEW_RELEASE) 
        return std::make_shared<New_Release>();        
    else 
        return std::make_shared<UnKnown>();
}

#endif 
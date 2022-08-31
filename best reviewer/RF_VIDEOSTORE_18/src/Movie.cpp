// Movie.cpp
#include "Movie.h"
#include "MovieType.h"

// const int Movie::CHILDRENS;
// const int Movie::REGULAR;
// const int Movie::NEW_RELEASE;

Movie::Movie( const std::string& title, int priceCode )
{
    setPriceCode(priceCode);
    setTitle(title);
}

int Movie::getPriceCode() const { return m_type->getPriceCode(); }

void Movie::setPriceCode( int arg ) { m_type = MovieType::create(arg); }

std::string Movie::getTitle() const { return m_type->getTitle(); }

void Movie::setTitle(std::string title) { m_type->setTitle(title); } 

double Movie::payAmount(int DaysRented) {return m_type->payAmount(DaysRented); }
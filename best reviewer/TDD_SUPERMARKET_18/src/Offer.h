#ifndef _OFFER_H_
#define _OFFER_H_
#include "Product.h"
#include "SpecialOfferType.h"

class Offer {
public:
	SpecialOfferType offerType;
	Product product;
	double argument;

	Offer(SpecialOfferType offerType, Product product, double argument)
	{
		this->offerType = offerType;
		this->product = product;
		this->argument = argument;
	}
	Offer() {}
	Offer(const Offer& o);
	Product getProduct() { return product; }
};

#endif
#ifndef _TELLER_H_
#define _TELLER_H_

#include <map>
#include <vector>
#include "ShoppingCart.h"
#include "SupermarketCatalog.h"
#include "Offer.h"

class Teller {
public:
	Teller(SupermarketCatalog & catalog):catalog(catalog) { }	
	void addSpecialOffer(SpecialOfferType offerType, Product& product, double argument);
	void checksOutArticlesFrom(ShoppingCart& theCart, Receipt& receipt);

private:
	SupermarketCatalog & catalog;
	map<string, Offer> offers;
};

#endif
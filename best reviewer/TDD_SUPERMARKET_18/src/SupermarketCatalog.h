#ifndef _SUPERMARKETCATALOG_H_
#define _SUPERMARKETCATALOG_H_
#include "Product.h"


class SupermarketCatalog {
public:
	virtual void addProduct(Product& product, double price) {}
	virtual double getUnitPrice(const Product& product) { return 0.0; }
};

#endif
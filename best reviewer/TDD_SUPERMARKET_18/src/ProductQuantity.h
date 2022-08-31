#ifndef _PRODUCTQUANTITY_H_
#define _PRODUCTQUANTITY_H_
#include "Product.h"

class ProductQuantity {
public:

	ProductQuantity(Product product, double weight);
	Product getProduct() { return product; }
	double getQuantity() { return quantity; }
private:
	Product product;
	double quantity;
};

#endif
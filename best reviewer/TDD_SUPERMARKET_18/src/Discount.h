#ifndef _DISCOUNT_H_
#define _DISCOUNT_H_
#include <string>
#include "Product.h"

class Discount {
public:
	Discount(Product product, string description, double discountAmount)
		:product(product), description(description), discountAmount(discountAmount) {}
	Discount(const Discount& o);
	string getDescription() { return description; }
	double getDiscountAmount() { return discountAmount; }
	Product getProduct() { return product; }
private:
	string description;
	double discountAmount;
	Product product;
};

#endif
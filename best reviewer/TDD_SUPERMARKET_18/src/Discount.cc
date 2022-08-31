#include "Discount.h"

Discount::Discount(const Discount& o)
{
	description = o.description;
	discountAmount = o.discountAmount;
	product = o.product;
}

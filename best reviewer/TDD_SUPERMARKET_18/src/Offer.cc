#include "Offer.h"

Offer::Offer(const Offer& o)
{
	offerType = o.offerType;
	product = o.product;
	argument = o.argument;
}

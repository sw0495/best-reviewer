#include "ShoppingCart.h"
#include <sstream>

void ShoppingCart::addItemQuantity(Product& product, double quantity)
{
	productQuantities[product] += quantity;
}

void ShoppingCart::handleOffers(Receipt& receipt, map<string, Offer> & offers, SupermarketCatalog& catalog)
{
	for (auto kv: productQuantities)
	{
		const Product& product = kv.first;		

		auto it = offers.find(product.getName());

		if ( it != offers.end())
		{
			auto& offer = it->second;
			double& quantity = kv.second;
			int quantityAsInt = (int)quantity;

			double unitPrice = catalog.getUnitPrice(product);

			if (offer.offerType == SpecialOfferType::ThreeForTwo && quantityAsInt > 2) {
				addDiscountToReceipt(receipt, 3, quantityAsInt, unitPrice, quantity, product, offer.argument);
			}
			else if (offer.offerType == SpecialOfferType::TwoForAmount && quantityAsInt >= 2) {
				addDiscountToReceipt(receipt, 2, quantityAsInt, unitPrice, quantity, product, offer.argument);
			}
			else if (offer.offerType == SpecialOfferType::FiveForAmount && quantityAsInt >= 5) {
				addDiscountToReceipt(receipt, 5, quantityAsInt, unitPrice, quantity, product, offer.argument);
			}			
			else if (offer.offerType == SpecialOfferType::TenPercentDiscount) {
				char buf[20];
				snprintf(buf, 20, "%.1f%% off", offer.argument);
				receipt.addDiscount(Discount(product, string(buf), quantity * unitPrice * offer.argument / 100.0));				
			}
		}
	}
}

void ShoppingCart::addDiscountToReceipt(Receipt& receipt, int x, int quantityAsInt, double unitPrice, double& quantity, const Product& product, double argument) {
    int numberOfXs = quantityAsInt / x;
	double discountTotal = unitPrice * quantity - (argument * numberOfXs + quantityAsInt % x * unitPrice);
	receipt.addDiscount(Discount(product, to_string(x) + string(" for ") + to_string(argument), discountTotal));
}

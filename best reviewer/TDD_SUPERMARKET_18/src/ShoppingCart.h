#ifndef _SHOPPINGCART_H_
#define _SHOPPINGCART_H_
#include <vector>
#include <map>
#include "Product.h"
#include "Receipt.h"
#include "ShoppingCart.h"
#include "ProductQuantity.h"
#include "Offer.h"
#include "SupermarketCatalog.h"

class ShoppingCart {
public:
	
	void addItem(Product& product) { addItemQuantity(product, 1.0); }

	map<Product, double>& getProductQuantities() { return productQuantities; }

	void addItemQuantity(Product& product, double quantity);

	void handleOffers(Receipt& receipt, map<string, Offer>& offers, SupermarketCatalog& catalog);

	void addDiscountToReceipt(Receipt& receipt, int x, int quantityAsInt, double unitPrice, double& quantity, const Product& product, double argument);
	
private:	
	
	map<Product, double> productQuantities;
};

#endif
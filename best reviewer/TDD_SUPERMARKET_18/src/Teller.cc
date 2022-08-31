#include "Teller.h"


void Teller::addSpecialOffer(SpecialOfferType offerType, Product& product, double argument)
{
    offers[product.getName()] = Offer(offerType, product, argument);
}

void Teller::checksOutArticlesFrom(ShoppingCart& theCart, Receipt& receipt)
{
    map<Product, double>& productQuantities = theCart.getProductQuantities();

    for (auto& kv : productQuantities) {
        const Product& product = kv.first;
        const double& quanity = kv.second;

        double unitPrice = catalog.getUnitPrice(product);
        double price = quanity * unitPrice;
        receipt.addProduct(product, quanity, unitPrice, price);
    }
    theCart.handleOffers(receipt, offers, catalog);
}

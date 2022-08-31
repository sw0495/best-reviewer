#include "Product.h"

Product::Product(double quantity, double itemPrice)
    : m_quantity(quantity), m_itemPrice(itemPrice)
{        
}

double Product::getPrice() {
    double basePrice = m_quantity * m_itemPrice;
    double discountFactor;
    
    if (basePrice > 1000) {
        discountFactor = 0.95;
    }
    else {
        discountFactor = 0.98;
    }
    return basePrice * discountFactor;
}




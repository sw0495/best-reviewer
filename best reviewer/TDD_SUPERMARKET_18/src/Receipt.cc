#include "Receipt.h"


double Receipt::getTotalPrice()
{
    double total = 0.0;
    for (auto item : receiptItems)
        total += item.getTotalPrice();

    for (auto item : discounts)
        total -= item.getDiscountAmount();
        
    return total;
}

void Receipt::addProduct(Product p, double quantity, double price, double totalPrice)
{
    receiptItems.push_back(ReceiptItem(p, quantity, price, totalPrice));
}

void Receipt::addDiscount(Discount discount)
{
    discounts.push_back(discount);
}


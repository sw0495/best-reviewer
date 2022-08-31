#include "ReceiptItem.h"

ReceiptItem::ReceiptItem(Product p, double quantity, double price, double totalPrice)
{
    this->product = p;
    this->quantity = quantity;
    this->price = price;
    this->totalPrice = totalPrice;
}

bool ReceiptItem::operator==(const ReceiptItem& o)
{
    return (product == o.product) && (this->quantity == o.quantity)
        && (this->price == o.price) && (this->totalPrice == price);
}

bool ReceiptItem::operator<(const ReceiptItem& o)
{
    return product < o.product;
}

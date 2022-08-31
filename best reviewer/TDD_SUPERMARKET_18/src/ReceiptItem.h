#ifndef _RECEIPTITEM_H_
#define _RECEIPTITEM_H_
#include "Product.h"

class ReceiptItem {
public:
	ReceiptItem(Product p, double quantity, double price, double totalPrice);
	double getPrice() { return price; }
	Product getProduct() { return product; }
	double getQuantity() { return quantity; }
	double getTotalPrice() { return totalPrice; }

	// 객체 비교
	bool operator == (const ReceiptItem& o);
	bool operator < (const ReceiptItem& o);
private:
	Product product;
	double price;
	double totalPrice;
	double quantity;	
};

#endif
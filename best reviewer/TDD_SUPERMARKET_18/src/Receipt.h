#ifndef _RECEIPT_H_
#define _RECEIPT_H_
#include <vector>
#include "ReceiptItem.h"
#include "Discount.h"
#include "Product.h"

using namespace std;

class Receipt {
public:

	double getTotalPrice();
	void addProduct(Product p, double quantity, double price, double totalPrice);
	void addDiscount(Discount discount);

	vector<ReceiptItem>& getReceiptItems() { return receiptItems; }
	vector<Discount>& getDiscounts() { return discounts; }
	
private:
	vector<ReceiptItem> receiptItems;
	vector<Discount> discounts;
};

#endif
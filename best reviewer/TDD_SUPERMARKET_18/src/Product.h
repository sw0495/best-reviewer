#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <string>
#include "ProductUnit.h"

using namespace std;

class Product {
public:
	Product() {}
	Product(string name, ProductUnit unit);
	Product(const Product& product);
	void setValue(string name, ProductUnit unit);
	string getName() const { return name; }
	ProductUnit getUnit() const { return unit; }
	// 객체 비교
	// 1. 객체 비교
	// 2. == 연산자 오버로딩
	bool operator == (const Product& p) const;
	bool operator < (const Product& p) const;
private:
	string name;
	ProductUnit unit;
};

#endif
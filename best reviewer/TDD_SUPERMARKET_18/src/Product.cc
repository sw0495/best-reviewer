#include "Product.h"
#include "ProductUnit.h"

Product::Product(string name, ProductUnit unit)
{
	this->name = name;
	this->unit = unit;
}

Product::Product(const Product& product)
{
	this->name = product.name;
	this->unit = product.unit;
}

void Product::setValue(string name, ProductUnit unit)
{
	this->name = name;
	this->unit = unit;
}

bool Product::operator == (const Product& p) const
{
	return (name == p.name) && (unit == p.unit);
}

bool Product::operator < (const Product& p) const{
	return name < p.name;
}
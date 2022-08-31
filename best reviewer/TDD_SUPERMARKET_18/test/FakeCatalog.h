#include <map>
#include <string>
#include "../src/Product.h"
#include "../src/SupermarketCatalog.h"

using namespace std;

class FakeCatalog : public SupermarketCatalog {
public:
	void addProduct(Product& product, double price) override {
		products[product.getName()] = product;
		prices[product.getName()] = price;
	}
	double getUnitPrice(const Product& product) override {
		return prices[product.getName()];
	}
private:
	map<string, Product> products;
	map<string, double> prices;
};

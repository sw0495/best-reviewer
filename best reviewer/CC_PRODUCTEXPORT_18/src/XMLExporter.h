
#include <string>
#include <vector>
#include "Store.h"
#include "Order.h"

class XMLExporter {
    std::string xml;
    double tax;
public:
    std::string export_full(std::vector<Order*> orders);
    std::string export_tax_details(std::vector<Order*> orders);
    std::string export_store(Store* store);
    std::string export_history(std::vector<Order*> orders);

    void export_full_orders(Order *order);
    void export_full_products(Product * product);
    void export_tax_orders(Order *order);
    void export_tax_products(Product * product);
    void export_store_products(Store *store, Product * product);
    void export_history_orders(Order *order);
    void export_history_products(Product * product);
    void printheader();
    void get_order_id(Order *order);
    void get_product_id(Product * product);
    void get_product_weight(Product * product);
    std::vector<Product *> get_order_products(Order *order);

private:
    std::string stylist_for(Product*);
    std::string make_formatted_double(double);
};


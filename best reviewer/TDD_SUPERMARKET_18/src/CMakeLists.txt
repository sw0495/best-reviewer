set(SOURCES
    Discount.cc Offer.cc 
    Product.cc ProductQuantity.cc 
    Receipt.cc ReceiptItem.cc ReceiptPrinter.cc
    ShoppingCart.cc
    SupermarketCatalog.cc
    Teller.cc
    HtmlReceiptPrinter.cc
)
add_library(Supermarket STATIC ${SOURCES})

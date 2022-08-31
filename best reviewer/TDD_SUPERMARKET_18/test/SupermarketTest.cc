#include <gtest/gtest.h>
#include <string>
#include <ApprovalTests.hpp>

#include "../src/SupermarketCatalog.h"
#include "../src/Product.h"
#include "../src/Teller.h"
#include "../src/ShoppingCart.h"
#include "../src/Receipt.h"
#include "../src/ReceiptPrinter.h"
#include "../src/HtmlReceiptPrinter.h"

#include "FakeCatalog.h"

#include <string>

using namespace std;

//#define APPROVALS_GOOGLETEST
#include "../lib/ApprovalTests.hpp"

namespace {

    TEST(SupermarketTest, twentyPercentDiscount) {
        // Arrange            
        FakeCatalog catalog;
        Product apples("apples", ProductUnit::Kilo);
        catalog.addProduct(apples, 1.99);

        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::TenPercentDiscount, apples, 20.0);

        ShoppingCart cart;
        cart.addItemQuantity(apples, 2.5);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(3.98, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(apples, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(1.99, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(2.5 * 1.99, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(2.5, receiptItem.getQuantity());    

    }   

    TEST(SupermarketTest, tenPercentDiscount) {
        // Arrange            
        FakeCatalog catalog;
        Product rice("rice", ProductUnit::Each);
        catalog.addProduct(rice, 2.49);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::TenPercentDiscount, rice, 10.0);

        ShoppingCart cart;
        cart.addItemQuantity(rice, 10.0);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(22.41, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(rice, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(2.49, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(10.0 * 2.49, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(10.0, receiptItem.getQuantity());    

    }

    TEST(SupermarketTest, ThreeForTwo) {
        // Arrange            
        FakeCatalog catalog;
        Product toothbrush("toothbrush", ProductUnit::Each);
        catalog.addProduct(toothbrush, 0.99);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::ThreeForTwo, toothbrush, 1.98);

        ShoppingCart cart;
        cart.addItemQuantity(toothbrush, 3);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(1.98, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(toothbrush, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(0.99, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(3 * 0.99, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(3, receiptItem.getQuantity());    

    }

    TEST(SupermarketTest, FiveForAmount) {
        // Arrange            
        FakeCatalog catalog;
        Product toothpaste("toothpaste", ProductUnit::Each);
        catalog.addProduct(toothpaste, 1.79);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::FiveForAmount, toothpaste, 7.49);

        ShoppingCart cart;
        cart.addItemQuantity(toothpaste, 5);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(7.49, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(toothpaste, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(1.79, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(5 * 1.79, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(5, receiptItem.getQuantity());    

    }

    TEST(SupermarketTest, TwoForAmount) {
        // Arrange            
        FakeCatalog catalog;
        Product tomato("tomato", ProductUnit::Each);
        catalog.addProduct(tomato, 0.69);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::TwoForAmount, tomato, 0.99);

        ShoppingCart cart;
        cart.addItemQuantity(tomato, 2);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(0.99, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(tomato, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(0.69, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(2 * 0.69, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(2, receiptItem.getQuantity());    

    }

    TEST(SupermarketTest, BundlePercentDiscount) {
        // Arrange            
        FakeCatalog catalog;
        Product milk("milk", ProductUnit::Each);
        catalog.addProduct(milk, 1.5);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::BundlePercentDiscount, milk, 12.5);

        ShoppingCart cart;
        cart.addItemQuantity(milk, 12);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ASSERT_FLOAT_EQ(12.5, receipt.getTotalPrice());
        EXPECT_EQ(1, receipt.getDiscounts().size());
        ASSERT_EQ(1, receipt.getReceiptItems().size());

        ReceiptItem& receiptItem = receipt.getReceiptItems()[0];
        ASSERT_EQ(milk, receiptItem.getProduct());        
        ASSERT_FLOAT_EQ(1.5, receiptItem.getPrice());
        ASSERT_FLOAT_EQ(12 * 1.5, receiptItem.getTotalPrice());
        ASSERT_FLOAT_EQ(12, receiptItem.getQuantity());

    }

    //approvaltest
    TEST(ReceiptPrinterTest, printReceipt) {
        // Arrange            
        FakeCatalog catalog;
        Product candy("candy", ProductUnit::Each);
        catalog.addProduct(candy, 1.6);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::TenPercentDiscount, candy, 10.0);

        ShoppingCart cart;
        cart.addItemQuantity(candy, 10);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        ReceiptPrinter receiptPrinter;
        string result = receiptPrinter.printReceipt(receipt);  

        ApprovalTests::Approvals::verify(result);
    }

    TEST(HtmlReceiptPrinterTest, htmlPrintReceipt) {
        // Arrange            
        FakeCatalog catalog;
        Product candy("candy", ProductUnit::Each);
        catalog.addProduct(candy, 1.6);
  
        Teller teller(catalog);
        teller.addSpecialOffer(SpecialOfferType::TenPercentDiscount, candy, 10.0);

        ShoppingCart cart;
        cart.addItemQuantity(candy, 10);
        
        Receipt receipt;
        teller.checksOutArticlesFrom(cart, receipt);
        
        HtmlReceiptPrinter htmlReceiptPrinter;
        string result = htmlReceiptPrinter.printReceipt(receipt);  

        ApprovalTests::Approvals::verify(result);
    }




}
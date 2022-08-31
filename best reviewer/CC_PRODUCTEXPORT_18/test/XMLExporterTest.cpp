#include "gtest/gtest.h"
#define APPROVALS_GOOGLETEST_EXISTING_MAIN
#include "../lib/ApprovalTests.hpp"
#undef APPROVALS_GOOGLETEST_EXISTING_MAIN

#include "../src/XMLExporter.h"

#include <vector>
#include "../src/Util.h"
#include "../src/StoreEvent.h"

#include <regex>

namespace XMLExporterTest {
    std::string scrubDate(const std::string &input) {
        static const auto regex = std::regex("createdAt='[^']+'");

        int matchNumber = 1;
        auto result = input;
        std::smatch m;
        if (std::regex_search(result, m, regex)) {
            auto guid_match = m.str();
            auto replacement = "createdAt='date_" + std::to_string(matchNumber) + "'";
            result = ApprovalTests::StringUtils::replaceAll(result, guid_match, replacement);
            matchNumber += 1;
        }
        return result;
    }

    // void verifyXml(std::string xml, ApprovalTests::Options options = ApprovalTests::Options()) {
    //     xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
    //     ApprovalTests::Approvals::verify(xml, options.fileOptions().withFileExtension(".xml"));
    // }

    void verifyXml(std::string xml, std::string extension=".xml") {
        xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
        ApprovalTests::Approvals::verifyWithExtension(xml,extension);
    }


    Product* CherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99, "USD"));
    Product* RosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99, "USD"));
    Product* BlusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99, "USD"));
    Product* EyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99, "USD"));
    Product* WildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99, "USD"));
    Product* CocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99, "USD"));
    std::vector<Product *> storeProducts = {
            CherryBloom, RosePetal, BlusherBrush, EyelashCurler, WildRose, CocoaButter
    };

    Store* FlagshipStore = new Store("Nordstan", "4189", storeProducts);
    /* Store events add themselves to the stocked items at their store */
    Product* Masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01",
                                FlagshipStore, new Price(119.99, "USD"));
    Product* Makeover = new StoreEvent("Makeover", "EVENT02",
                            FlagshipStore, new Price(149.99, "USD"));

    std::vector<Product *> orderProducts = { Makeover, EyelashCurler};

    Order* RecentOrder = new Order("1234", from_iso_date("2018-09-01T00:00Z"),
                            FlagshipStore, orderProducts);

    std::vector<Product *> oldOrderProducts = { CherryBloom, Masterclass };

    Order* OldOrder = new Order("1235", from_iso_date("2017-09-01T00:00Z"),
                        FlagshipStore, oldOrderProducts);

    auto orders = std::vector<Order *>{RecentOrder, OldOrder};

    TEST(XMLReporterTestSuite, testExportStore) {
        // "export store"
        verifyXml(XMLExporter().export_store(FlagshipStore));
    }

    TEST(XMLReporterTestSuite, testExportFull) {
        // "export full"
        verifyXml(XMLExporter().export_full(orders));
    }

    TEST(XMLReporterTestSuite, testExportTaxDetails) {
        // "export tax details"
        verifyXml(XMLExporter().export_tax_details(orders));
    }

    // TEST(XMLReporterTestSuite, testExportStore) {    // higher Approval-test ver.
    //     // "export history"
    //     auto options = ApprovalTests::Options().withScrubber(scrubDate);
    //     verifyXml(XMLExporter().export_history(orders), options);
    // }

}


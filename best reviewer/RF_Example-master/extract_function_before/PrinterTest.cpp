#include <gtest/gtest.h>
#include "Printer.h"

using testing::InitGoogleTest;
using testing::Test;
using testing::TestCase;
 
TEST(printerTest, test) {
    Printer printer;
    Order buzz(1);
    Order cellphone(2);
    Order notebook(3);
    printer.orders.push_back(buzz);
    printer.orders.push_back(cellphone);
    printer.orders.push_back(notebook);

    string expected = string("********************************\n")
                + string("******   Customer totals   *****\n")
                + string("********************************\n")
                + string("name: Digital City\n")
                + string("amount: 6");

    ASSERT_EQ(expected, printer.PrintOwing("Digital City"));
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <cstdio>
#include <fstream>
#include <string>
#include "../src/PrimePrinter.h"
#include "gtest/gtest.h"

using namespace std;

namespace {

    class PrimePrinterTest : public testing::Test
    {
    protected:
        ofstream write;        
        ifstream read;
        ifstream gold;
        streambuf* streambufcout;
        streambuf* streambufresult;

        void SetUp() override {            
            write.open("lead.txt");
            streambufcout = cout.rdbuf();
            streambufresult = write.rdbuf();
            cout.rdbuf(streambufresult);
        }

        void TearDown() override {
        
            write.close();
            cout.rdbuf(streambufcout);            
            //remove("lead.txt");
        }
    };

    TEST_F(PrimePrinterTest, OutputMatchesGold) {
        
        PrimePrinter pp;
        pp.print();             
        write.close();
        
        try {
            read.open("lead.txt");
            gold.open("gold.txt");
            string buf1, buf2;
            while (gold.peek() != EOF)
            {
                getline(read, buf1);
                getline(gold, buf2);
                ASSERT_STREQ(buf1.c_str(), buf2.c_str());
            }
        }
        catch (...) {
            read.close();
            gold.close();
        }
    }

}  // namespace

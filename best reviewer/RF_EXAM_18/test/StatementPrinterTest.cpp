#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

#include "../src/Play.h"
#include "../src/Invoice.h"
#include "../src/Performance.h"
#include "../src/StatementPrinter.h"

#include <map>

using namespace std;

namespace {


TEST(StatementTestFixture, valueTest) {

    map<string, shared_ptr<Play>> plays; 

    plays.insert(make_pair<string, shared_ptr<Play>>("hamlet",  make_shared<Play>("Hamlet", "tragedy")));
    plays.insert(make_pair<string, shared_ptr<Play>>("as-like", make_shared<Play>("As You Like It", "comedy")));
    plays.insert(make_pair<string, shared_ptr<Play>>("othello", make_shared<Play>("Othello", "tragedy")));
    
    vector<Performance> performances;
    performances.push_back(Performance("hamlet", 55));
    performances.push_back(Performance("as-like", 35));
    performances.push_back(Performance("othello", 40));

    Invoice invoice("BigCo", performances);            

    StatementPrinter statementPrinter;
    string result = statementPrinter.print(invoice, plays);                 

    ApprovalTests::Approvals::verify(result);
}


TEST(StatementTestFixture, throwTest) {

    map<string, shared_ptr<Play>> plays; 

    plays.insert(make_pair<string, shared_ptr<Play>>("Henry V",  make_shared<Play>("Henry V", "tragedy")));
    plays.insert(make_pair<string, shared_ptr<Play>>("as-like", make_shared<Play>("As You Like It", "pastoral")));
    
    vector<Performance> performances;
    performances.push_back(Performance("Henry V", 53));
    performances.push_back(Performance("as-like", 55));
    
    Invoice invoice("BigCoII", performances);            

    StatementPrinter statementPrinter;
    ASSERT_THROW(statementPrinter.print(invoice, plays), std::domain_error);
}

}

    
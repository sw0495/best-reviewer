#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

#include "../src/LibraryBook.cc"

using namespace ApprovalTests;
using namespace testing;

TEST(GoogleTestStarter, YouCanVerifyValue)
{
    ApprovalTests::Approvals::verify(42);
}

TEST(GoogleTestStarter, YouCanVerifyObject)
{
    LibraryBook harry_potter(
        "Harry Potter and the Goblet of Fire", "J.K. Rowling",
        30, "English", 752, "978-0439139595");

    Approvals::verify(harry_potter, [](const LibraryBook& b, std::ostream& os) {
        os << "title: " << b.title << "\n"
            << "author: " << b.author << "\n"
            << "available_copies: " << b.available_copies << "\n"
            << "language: " << b.language << "\n"
            << "pages: " << b.pages << "\n"
            << "isbn: " << b.isbn << "\n";
        });
}

TEST(ApprovedTest, YouCanVerifyVectors)
{
    std::vector<std::string> v{"hello", "world"};
    auto converter = [](std::string s, std::ostream& os) { 
        os << s << " => " << s[0]; 
    };
    Approvals::verifyAll("FIRST LETTER", v, converter);    
}

TEST(ApprovedTest, YouCanVerifyIteratorRange)
{
    std::vector<std::string> v{"hello", "world"};
    auto converter = [](std::string s, std::ostream& os) { 
        os << s << " => " << s[0]; 
    };
    Approvals::verifyAll("FIRST LETTER", v.begin(), v.end(), converter);    
}


TEST(ApprovedTest, VerifyCombinations) {

    std::vector<std::string> letters{"a", "b"};
    auto converter = [](const std::string& s1,
                        const std::string& s2,
                        const std::string& s3) { return s1 + s2 + s3; };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        converter, letters, letters, letters);    
}





// Include header files for test frameworks 
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

#include "../src/Movie.h"
#include "../src/Rental.h"
#include "../src/Customer.h"

using namespace std;

namespace VideoStoreTests { 
    TEST( VideoStoreTest, fail_test ) {
        //FAIL();
    }

    Movie regular1{ "삼시세끼 정선편", Movie::REGULAR };
    Movie regular2{ "삼시세끼 어촌편", Movie::REGULAR };
    Movie newRelease1{ "삼시세끼 바다목장편", Movie::NEW_RELEASE };
    Movie newRelease2{ "삼시세끼 산촌편",Movie::NEW_RELEASE };
    Movie children1{ "삼시네세끼", Movie::CHILDRENS };
    Movie children2{ "삼시네세끼", Movie::CHILDRENS };
    Movie unknown1{ "삼시세끼 달나라편", 100 };
    Customer customer{"John"};

    class VideoStoreTestFixture : public ::testing::Test {    
    protected:
        static void SetUpTestCase() {
        customer.addRental( {regular1, 2} );
        customer.addRental( {regular2, 3} );
        customer.addRental( {newRelease1, 1} );
        customer.addRental( {newRelease2, 2} );
        customer.addRental( {children1, 3} );
        customer.addRental( {children2, 4} );
        customer.addRental( {unknown1, 5} );
        }

    };

    TEST_F(VideoStoreTestFixture, UnitTest1) {
        std::vector< Rental > rentals = customer.getCustomerRentals();
        Movie movie = rentals[3].getMovie();
        int amount = movie.payAmount(Movie::NEW_RELEASE);

        ASSERT_EQ(3, amount); 
    }

    TEST_F(VideoStoreTestFixture, testsatement) {
        std::string receipt = customer.statement();
        ApprovalTests::Approvals::verify(receipt);
    }
   
    TEST_F(VideoStoreTestFixture, testHtmlsatement) {
        std::string receipt = customer.htmlstatement();
        ApprovalTests::Approvals::verify(receipt);
    }

} // Namespace VideoStoreTests


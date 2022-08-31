#include "gtest/gtest.h"
#define APPROVALS_GOOGLETEST_EXISTING_MAIN
#include "../lib/ApprovalTests.hpp"
#undef APPROVALS_GOOGLETEST_EXISTING_MAIN

// Main must be provided:
int main( int argc, char **argv ) {

  ::testing::InitGoogleTest( &argc, argv );

  ApprovalTests::initializeApprovalTestsForGoogleTests();

  //

  return RUN_ALL_TESTS();
}


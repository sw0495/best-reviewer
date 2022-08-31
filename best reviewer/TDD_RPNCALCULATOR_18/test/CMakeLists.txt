cmake_minimum_required(VERSION 3.8)
set(PROJECT RPNCalculatorTest)

set(SOURCES
RPNCalculatorTest.cc
)

# text tests
add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        RPNCalculator
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)


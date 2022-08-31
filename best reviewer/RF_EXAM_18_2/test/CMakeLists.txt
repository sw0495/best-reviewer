cmake_minimum_required(VERSION 3.8)
set(PROJECT StatementPrinterTest)

set(MAIN
    googletest_approval_main.cc
)
set(SOURCES
    StatementPrinterTest.cpp
)

add_executable(${PROJECT} ${MAIN} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        lib
        gtest
        gtest_main
        StatementPrinter
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)
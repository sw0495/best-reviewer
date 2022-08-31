cmake_minimum_required(VERSION 3.8)
set(PROJECT PrimePrinterTest)
set(SOURCES
    PrimePrinterTest.cc
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        PrimePrinter
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

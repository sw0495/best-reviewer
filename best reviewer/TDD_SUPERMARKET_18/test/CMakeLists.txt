cmake_minimum_required(VERSION 3.8)
set(PROJECT SupermarketTest)

set(MAIN
    googletest_approval_main.cc
)

set(SOURCES
    SupermarketTest.cc
)

add_executable(${PROJECT} ${MAIN} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        lib
        gtest
        Supermarket
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)


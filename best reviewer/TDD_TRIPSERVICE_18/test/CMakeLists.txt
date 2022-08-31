cmake_minimum_required(VERSION 3.8)
set(PROJECT TripServiceTests)

# text tests
set(SOURCES
    TripServiceTests.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main
        TripService
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)


cmake_minimum_required(VERSION 3.8)
set(PROJECT TVControllerTests)

# text tests
set(SOURCES
    TVControllerTests.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main
        TVController
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)


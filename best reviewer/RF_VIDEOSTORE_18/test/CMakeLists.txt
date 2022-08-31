cmake_minimum_required(VERSION 3.8)
set(PROJECT VideoStoreTest)

set(MAIN
    googletest_approval_main.cc
)
set(SOURCES
    VideoStoreTest.cc
)

add_executable(${PROJECT} ${MAIN} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        lib
        gtest
        gtest_main
        videoStore
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)
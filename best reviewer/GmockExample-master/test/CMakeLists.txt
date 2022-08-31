cmake_minimum_required(VERSION 3.8)

# ================ SimpleMockTest
set(PROJECT SimpleMockTest)

set(SOURCES
    SimpleMockTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main
        GmockSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ NiceStrictTest
set(PROJECT NiceStrictTest)

set(SOURCES
    NiceStrictTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main   
        GmockSample     
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ BuiltInDefault
set(PROJECT BuiltInDefault)

set(SOURCES
    BuiltInDefault.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main   
        GmockSample     
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ GmockActions
set(PROJECT GmockActions)

set(SOURCES
    GmockActions.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main   
        GmockSample     
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ GmockOutput
set(PROJECT GmockOutput)

set(SOURCES
    GmockOutput.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        gmock
        gmock_main   
        GmockSample     
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)



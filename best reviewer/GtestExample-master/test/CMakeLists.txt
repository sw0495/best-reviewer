cmake_minimum_required(VERSION 3.8)

# ================ SimpleAssertionTest
set(PROJECT SimpleAssertionTest)

set(SOURCES
    SimpleAssertionTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ StringAssertionTest
set(PROJECT StringAssertionTest)

set(SOURCES
    StringAssertionTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ TestFixtureTest
set(PROJECT TestFixtureTest)

set(SOURCES
    TestFixtureTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ AssertPredTest
set(PROJECT AssertPredTest)

set(SOURCES
    AssertPredTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ FloatingPointTest
set(PROJECT FloatingPointTest)

set(SOURCES
    FloatingPointTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ ParameterizedTest
set(PROJECT ParameterizedTest)

set(SOURCES
    ParameterizedTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ CustomParameterizedTest
set(PROJECT CustomParameterizedTest)

set(SOURCES
    CustomParameterizedTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)


# ================ FriendTest
set(PROJECT FriendTest)

set(SOURCES
    FriendTest.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ ApprovalTest
set(PROJECT ApprovalTest)

set(SOURCES
    ApprovalTest.cpp
)

set(MAIN
    googletest_approval_main.cc
)

add_executable(${PROJECT} ${MAIN} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        lib
        gtest
        gtest_main
        GtestSample
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# ================ MatcherTest
#set(PROJECT MatcherTest)
#
#set(SOURCES
#    MatcherTest.cpp
#)
#
#add_executable(${PROJECT} ${SOURCES})
#
#target_link_libraries(${PROJECT}
#    PUBLIC
#        gtest
#        gtest_main
#        gmock
#        gmock_main
#        GtestSample
#)
#
#add_test(
#    NAME ${PROJECT}
#    COMMAND ${PROJECT}
#)




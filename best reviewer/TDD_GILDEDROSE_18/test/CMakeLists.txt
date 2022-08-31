cmake_minimum_required(VERSION 3.8)
set(PROJECT GildedRoseTextTests)

set(SOURCES
    GildedRoseTextTests.cc
)

# text tests
# add_executable(${PROJECT} ${SOURCES})

# target_link_libraries(${PROJECT}
#     PUBLIC
#         GildedRose
# )

# add_test(
#     NAME ${PROJECT}
#     COMMAND ${PROJECT}
# )

# unit tests
set(PROJECT GildedRoseUnitTests)

set(SOURCES
    GildedRoseUnitTests.cc
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
        gtest
        gtest_main
        GildedRose
)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)

# approval tests
# set(PROJECT GildedRoseApprovalTests)

# set(MAIN
#     googletest_approval_main.cc
# )
# set(SOURCES
#     GildedRoseApprovalTests.cc
# )

# add_executable(${PROJECT} ${MAIN} ${SOURCES})

# target_link_libraries(${PROJECT}
#     PUBLIC
#         lib
#         gtest
#         GildedRose
# )

# add_test(
#     NAME ${PROJECT}
#     COMMAND ${PROJECT}
# )
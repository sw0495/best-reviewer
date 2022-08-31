cmake_minimum_required(VERSION 3.0.1)
set(PROJECT_NAME AccountTest)
project(${PROJECT_NAME})

set(SRCS
        Account.cpp
        AccountTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(AccountTest gtest)




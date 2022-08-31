cmake_minimum_required(VERSION 3.0.1)
set(PROJECT_NAME ZipcodeTest)
project(${PROJECT_NAME})

set(SRCS
        Customer.h
        Address.h
        Order.h
        ZipcodeTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(ZipcodeTest gtest)




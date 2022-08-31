cmake_minimum_required(VERSION 3.0.1)
set(PROJECT_NAME printerTest)
project(${PROJECT_NAME})

set(SRCS
        Order.cpp
        Printer.cpp
        PrinterTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(printerTest gtest)




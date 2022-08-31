cmake_minimum_required(VERSION 3.0.1)
set(PROJECT_NAME ProductTest)
project(${PROJECT_NAME})

set(SRCS
        Product.cpp
        ProductTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(ProductTest gtest)




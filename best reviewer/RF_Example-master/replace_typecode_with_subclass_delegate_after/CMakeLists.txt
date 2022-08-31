cmake_minimum_required(VERSION 3.0.1)
set( CMAKE_CXX_STANDARD 11 )
set(PROJECT_NAME EmployeeTest)
project(${PROJECT_NAME})

set(SRCS
        Employee.cpp
        EmployeeType.cpp
        EmployeeTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(EmployeeTest gtest)




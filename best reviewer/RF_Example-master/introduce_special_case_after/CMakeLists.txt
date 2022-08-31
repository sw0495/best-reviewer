cmake_minimum_required(VERSION 3.0.1)
set(PROJECT_NAME BillingPrinterTest)
project(${PROJECT_NAME})

set(SRCS
        BillInfo.h
        BillingPlan.h
        BillingPrinter.cpp
        Company.h
        Customer.h
        PaymentHistory.h
        BillingPrinterTest.cpp
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(BillingPrinterTest gtest)




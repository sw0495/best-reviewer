cmake_minimum_required(VERSION 3.0.1)
set( CMAKE_CXX_STANDARD 11 )
set(PROJECT_NAME LightDriverTest)
project(${PROJECT_NAME})

set(SRCS
        LightDriver.c
        X10LightDriver.c
        AcmeWirelessLightDriver.c
        MemMappedLightDriver.c
        common.c
        LightDriverTest.cc
        )

add_executable(${PROJECT_NAME}
        ${SRCS}
        )

target_link_libraries(LightDriverTest gtest)




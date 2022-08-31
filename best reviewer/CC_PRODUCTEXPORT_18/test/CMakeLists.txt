set(PROJECT ProductExportApprovalTests)
set(SOURCES
        unittest_main.cpp
        XMLExporterTest.cpp)
add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT} gtest src)
add_test(NAME ${PROJECT} COMMAND ${PROJECT})



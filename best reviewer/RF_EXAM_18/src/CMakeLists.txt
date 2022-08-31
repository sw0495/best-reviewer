set(SOURCES
    Invoice.h Performance.h Play.h Play.cpp PlayType.h PlayType.cpp StatementPrinter.cpp
)
add_library(StatementPrinter STATIC ${SOURCES})

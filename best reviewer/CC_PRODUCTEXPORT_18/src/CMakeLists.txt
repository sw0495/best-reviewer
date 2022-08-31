set(HEADERS
	Order.h
	Price.h
	Product.h
	Store.h
	StoreEvent.h
	TaxCalculator.h
	Util.h
	XMLExporter.h
)

set(SOURCES
	Order.cpp
	Price.cpp
	Product.cpp
	Store.cpp
	StoreEvent.cpp
	XMLExporter.cpp
)


add_library(src STATIC ${SOURCES} ${HEADERS})


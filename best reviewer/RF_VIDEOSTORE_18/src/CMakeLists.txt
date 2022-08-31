set(HEADERS
	Customer.h
	Movie.h
	Rental.h
)

set(SOURCES
	Customer.cpp
	Movie.cpp
)


add_library(videoStore STATIC ${SOURCES} ${HEADERS})


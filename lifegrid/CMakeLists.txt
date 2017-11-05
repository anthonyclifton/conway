project(lifegrid)

set(HEADER_FILES
        LifeGrid.h
        Cell.h
        )

set(SOURCE_FILES
        LifeGrid.cpp
        Cell.cpp)

add_library(lifegrid STATIC ${SOURCE_FILES} ${HEADER_FILES})
project(lifegrid)

set(HEADER_FILES
        LifeGrid.h
        )

set(SOURCE_FILES
        LifeGrid.cpp
        )

add_library(lifegrid STATIC ${SOURCE_FILES} ${HEADER_FILES})
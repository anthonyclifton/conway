project(lifegrid_loader)

set(HEADER_FILES
        Loader.h
        )

set(SOURCE_FILES
        Loader.cpp
        )

add_library(lifegrid_loader STATIC ${SOURCE_FILES} ${HEADER_FILES})
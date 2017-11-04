project(lifegrid_output)

set(HEADER_FILES
        Output.h
        )

set(SOURCE_FILES
        Output.cpp
        )

add_library(lifegrid_output STATIC ${SOURCE_FILES} ${HEADER_FILES})
cmake_minimum_required(VERSION 3.8)
project(Conway)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(conway_run ${SOURCE_FILES})

include_directories(lifegrid)
include_directories(lifegrid_loader)
include_directories(lifegrid_output)

add_subdirectory(lifegrid)
add_subdirectory(lifegrid_loader)
add_subdirectory(lifegrid_output)
add_subdirectory(lifegrid_tests)

target_link_libraries(conway_run lifegrid)
target_link_libraries(conway_run lifegrid_loader)
target_link_libraries(conway_run lifegrid_output)
target_link_libraries(conway_run ${CURSES_LIBRARIES})

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)
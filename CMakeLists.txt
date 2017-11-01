cmake_minimum_required(VERSION 3.8)
project(Conway)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(conway_run ${SOURCE_FILES})

include_directories(lifegrid)

add_subdirectory(lifegrid)
add_subdirectory(lifegrid_tests)

target_link_libraries(conway_run lifegrid)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)
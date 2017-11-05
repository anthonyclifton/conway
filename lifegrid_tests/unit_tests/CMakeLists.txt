include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runLifeGridTests
        testLifeGrid.cpp
        testLoader.cpp
        testCell.cpp)

target_link_libraries(runLifeGridTests gtest gtest_main)
target_link_libraries(runLifeGridTests lifegrid)
target_link_libraries(runLifeGridTests lifegrid_loader)
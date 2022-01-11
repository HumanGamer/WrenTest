cmake_minimum_required(VERSION 3.21)
project(WrenTest)

set(CMAKE_CXX_STANDARD 17)

include(cmake/lib/wren.cmake)

include_directories(lib/wren/src/include)

set(MAIN_SRC
    main.cpp
)

add_executable(WrenTest ${MAIN_SRC})
target_link_libraries(WrenTest WrenLib)

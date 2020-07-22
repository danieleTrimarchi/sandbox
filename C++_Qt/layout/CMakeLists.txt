cmake_minimum_required(VERSION 3.10)

# set the project name
project(Layout)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

# add the executable
add_executable(Layout main.cpp Grid.cpp)

target_link_libraries(Layout Qt5::Widgets Qt5::Core)
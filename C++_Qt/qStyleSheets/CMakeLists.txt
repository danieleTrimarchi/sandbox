cmake_minimum_required(VERSION 3.10)

# set the project name
project(QStyleSheets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# add the executable
add_executable(QStyleSheets main.cpp MainWindow.cpp)

target_link_libraries(QStyleSheets Qt5::Widgets)
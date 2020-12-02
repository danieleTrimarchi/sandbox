cmake_minimum_required(VERSION 3.3...3.12 FATAL_ERROR)

project (Eigentest)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Eigentest Eigentest.cpp)

target_include_directories(Eigentest
	PUBLIC
	C:/ThirdPartyPackages/eigen-3.3.8
)

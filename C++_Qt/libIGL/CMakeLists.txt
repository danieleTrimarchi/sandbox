cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# ----------------------------------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)
project(TEST LANGUAGES CXX)


set(EXENAME "test.exe" CACHE PATH "Path to Cascade libraries")

add_executable(${EXENAME} "main.cpp")

add_compile_definitions(${EXENAME})

include_directories(
	C:/sandbox/libIGL/libigl-master/include
	C:/sandbox/libIGL/libigl-master/external/eigen
	C:/sandbox/libIGL/libigl-master/external/glad/include
	C:/sandbox/libIGL/libigl-master/external/imgui/examples/libs/glfw/include)

# Request that particles be built with -std=c++17
# target_compile_features(BeamformerCuda8_Algo_1  PUBLIC cxx_std_17)
# set_property(TARGET BeamformerCuda8_Algo_1 PROPERTY CXX_STANDARD 17)
target_compile_features(${EXENAME} PUBLIC cxx_std_17)
SET(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# ----------------------------------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)
project(TEST LANGUAGES CXX)


set(EXENAME "test.exe")

add_executable(${EXENAME} "test.cpp")

add_compile_definitions(${EXENAME})

# Request that particles be built with -std=c++17
# target_compile_features(BeamformerCuda8_Algo_1  PUBLIC cxx_std_17)
# set_property(TARGET BeamformerCuda8_Algo_1 PROPERTY CXX_STANDARD 17)
target_compile_features(${EXENAME} PUBLIC cxx_std_11)
SET(CMAKE_CXX_STANDARD 11)

target_include_directories(${EXENAME} PUBLIC spdLogger/include)
#target_link_libraries(${EXENAME}  optimized )
#target_link_directories(${EXENAME} PRIVATE C:/ThirdPartyPackages/boost_1_69_0_46e5e284f2c321e7c687401f7dfe0ed5/stage/lib)



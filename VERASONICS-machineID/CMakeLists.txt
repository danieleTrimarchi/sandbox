cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# project(HELLOWORLD LANGUAGES CXX)

# set(HWEXENAME "Helloword.exe" CACHE PATH "Path to Cascade libraries")

# add_executable(${HWEXENAME} helloWorld.cpp)

# add_compile_definitions(${HWEXENAME})

# # Request that particles be built with -std=c++17
# # target_compile_features(BeamformerCuda8_Algo_1  PUBLIC cxx_std_17)
# # set_property(TARGET BeamformerCuda8_Algo_1 PROPERTY CXX_STANDARD 17)
# target_compile_features(${HWEXENAME} PUBLIC cxx_std_17)
# SET(CMAKE_CXX_STANDARD 17)

# ----------------------------------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)
project(VANTAGE_SN LANGUAGES CXX)

set(EXENAME "VantageSN" CACHE PATH "Path to Cascade libraries")

add_executable(${EXENAME} main.cpp)

add_compile_definitions(${EXENAME})

target_include_directories(${EXENAME} PRIVATE C:/sandbox/VERASONICS-machineID )

target_link_directories(${EXENAME} PRIVATE 
	.
	C:/prog/VERASONICS/build/artifacts/win64/win64
)

target_link_libraries(${EXENAME} 
	libVeraApi_dll
	VerasonicsCommon
	VerasonicsHal-NG
)

# Request that particles be built with -std=c++17
# target_compile_features(BeamformerCuda8_Algo_1  PUBLIC cxx_std_17)
# set_property(TARGET BeamformerCuda8_Algo_1 PROPERTY CXX_STANDARD 17)
target_compile_features(${EXENAME} PUBLIC cxx_std_17)
SET(CMAKE_CXX_STANDARD 17)

# We need to explicitly state that we need all CUDA files in the
# particle library to be built with -dc as the member functions
# could be called by other libraries and executables
set_target_properties(${EXENAME} PROPERTIES CUDA_SEPARABLE_COMPILATION ON )
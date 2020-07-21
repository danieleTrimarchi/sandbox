cmake_minimum_required(VERSION 3.3...3.12 FATAL_ERROR)

project(opencv_4_0_1_test)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)





file(GLOB FILE_EXEC
	"*.cpp"
)

add_executable(opencv_4_0_1_test ${FILE_EXEC})

set(INCLUDE_PATH C:/ThirdPartyPackages/opencv_4_0_1_01334afa7eaebde1a9953afa5d6c7164/include)
set(LIB_PATH C:/ThirdPartyPackages/opencv_4_0_1_01334afa7eaebde1a9953afa5d6c7164/x64/vc15/lib)

add_compile_options(/EHsc /MD)
add_definitions(-D_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH)

target_link_directories(opencv_4_0_1_test PRIVATE ${LIB_PATH})

target_link_libraries(opencv_4_0_1_test optimized
    opencv_world401
)

target_include_directories(opencv_4_0_1_test PRIVATE ${INCLUDE_PATH})

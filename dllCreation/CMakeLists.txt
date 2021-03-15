cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project (IconeusLicensingEXE)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
# Create the dll
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(IconeusLicensingDLL SHARED
            IconeusLicensing.cpp
            Keylok.cpp
            )

target_include_directories(IconeusLicensingDLL PUBLIC 
    C:/ThirdPartyPackages/boost_1_69_0_46e5e284f2c321e7c687401f7dfe0ed5
    C:/ThirdPartyPackages/KeyLock_cce909dc02729857df1c408401492288/Include
)

target_link_directories(IconeusLicensingDLL PRIVATE 
    C:/ThirdPartyPackages/boost_1_69_0_46e5e284f2c321e7c687401f7dfe0ed5/stage/lib
     C:/ThirdPartyPackages/KeyLock_cce909dc02729857df1c408401492288/lib
)

target_link_libraries(IconeusLicensingDLL
    kfunc64MT
)

# ----

# Create the main exe
#add_executable(IconeusLicensingEXE  "main.cpp" )
#
#add_compile_options(/EHsc /MD)
#add_definitions(-D_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH)
#
#target_include_directories(IconeusLicensingEXE PRIVATE 
#    C:/ThirdPartyPackages/KeyLock_cce909dc02729857df1c408401492288/Include
#)

#target_link_libraries(IconeusLicensingEXE
#    IconeusLicensingDLL
#)

# QUESTION : why shall I add the boost lib path, while this is already   
#            contained into IconeusLicensingAPI ? 
#target_link_directories(IconeusLicensingEXE  PRIVATE 
#    C:/ThirdPartyPackages/boost_1_69_0_46e5e284f2c321e7c687401f7dfe0ed5/stage/lib
#    C:/ThirdPartyPackages/KeyLock_cce909dc02729857df1c408401492288/lib
#)
#
#target_link_libraries(IconeusLicensingEXE optimized
#    kfunc64MT
#)


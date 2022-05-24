cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set( CMAKE_CXX_COMPILER "C:/Program Files/CodeBlocks/MinGW/bin/g++" )
#set( CMAKE_C_COMPILER "C:/Program Files/CodeBlocks/MinGW/bin/gcc" )

project(compiler VERSION 1.0)

include_directories(include)
#target_include_directories(output PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# link_directories(./ThirdParty/LibraryExample/)
# include_directories(ThirdParty/LibraryExample/include)

#file(GLOB_RECURSE SOURCES "src/*.cpp" main.cpp)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(output ${SOURCES})
#add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
# target_link_libraries (example ExampleLibrary)
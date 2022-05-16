cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(cmake-starter)

include_directories(include)
# link_directories(./ThirdParty/LibraryExample/)
# include_directories(ThirdParty/LibraryExample/include)

file(GLOB_RECURSE SOURCES "src/*.cpp" main.cpp)
add_executable(output ${SOURCES})
# target_link_libraries (example ExampleLibrary)
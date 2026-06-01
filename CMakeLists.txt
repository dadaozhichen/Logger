cmake_minimum_required(VERSION 3.10 )
project(Logger)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE src/*.cpp)
add_executable(main ${SOURCE} ) 
target_include_directories(main PRIVATE include)
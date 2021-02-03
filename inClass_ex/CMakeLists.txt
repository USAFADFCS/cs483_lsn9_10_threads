cmake_minimum_required(VERSION 3.6)
project(l9_in_class)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(l9_in_class ${SOURCE_FILES})

target_link_libraries(l9_in_class "-lpthread")

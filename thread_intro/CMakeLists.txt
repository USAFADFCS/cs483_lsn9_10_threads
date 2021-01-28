cmake_minimum_required(VERSION 3.6)
project(l9_thread_intro)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(l9_thread_intro ${SOURCE_FILES})

target_link_libraries(l9_thread_intro "-lpthread")

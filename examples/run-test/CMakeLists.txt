cmake_minimum_required(VERSION 3.14)
project(cppUTests-run-test LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(cppUTests REQUIRED)
endif()

set(sources run_test.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_executable(cppUTests-run-test)
target_sources(cppUTests-run-test PRIVATE ${sources})
target_link_libraries(cppUTests-run-test PRIVATE cppUTests::cppUTests)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(cppUTests-run-test cppUTests::cppUTests)
endif()
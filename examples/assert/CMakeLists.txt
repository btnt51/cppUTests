cmake_minimum_required(VERSION 3.14)
project(cppUTests-assert LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(cppUTests REQUIRED)
endif()

set(sources_assert assert.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources_assert})

add_executable(cppUTests-assert)
target_sources(cppUTests-assert PRIVATE ${sources_assert})
target_link_libraries(cppUTests-assert PRIVATE cppUTests::cppUTests)


project(cppUTests-assert-hint LANGUAGES CXX)
set(sources_assert_hint assert-hint.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources_assert_hint})

add_executable(cppUTests-assert-hint)
target_sources(cppUTests-assert-hint PRIVATE ${sources_assert_hint})
target_link_libraries(cppUTests-assert-hint PRIVATE cppUTests::cppUTests)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(cppUTests-assert cppUTests::cppUTests)
    win_copy_deps_to_target_dir(cppUTests-assert-hint cppUTests::cppUTests)
endif()
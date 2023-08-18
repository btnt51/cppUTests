cmake_minimum_required(VERSION 3.14)
project(cppUTests-assert-equal LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(cppUTests REQUIRED)
endif()

set(sources_assert assert-equal.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources_assert})

add_executable(cppUTests-assert-equal)
target_sources(cppUTests-assert-equal PRIVATE ${sources_assert})
target_link_libraries(cppUTests-assert-equal PRIVATE cppUTests::cppUTests)


project(cppUTests-assert-equal-hint LANGUAGES CXX)
set(sources_assert_hint assert-equal-hint.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources_assert_hint})

add_executable(cppUTests-assert-equal-hint)
target_sources(cppUTests-assert-equal-hint PRIVATE ${sources_assert_hint})
target_link_libraries(cppUTests-assert-equal-hint PRIVATE cppUTests::cppUTests)

if(NOT is_top_level)
    win_copy_deps_to_target_dir(cppUTests-assert-equal cppUTests::cppUTests)
    win_copy_deps_to_target_dir(cppUTests-assert-equal-hint cppUTests::cppUTests)
endif()
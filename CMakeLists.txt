cmake_minimum_required(VERSION 3.14)
project(cppUTests
    VERSION 1.2.0
    DESCRIPTION "Template for C++ library built with CMake"
    LANGUAGES CXX)

#----------------------------------------------------------------------------------------------------------------------
# general settings and options
#----------------------------------------------------------------------------------------------------------------------

include(cmake/utils.cmake)
include(GNUInstallDirs)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

# CPPUTESTS_SHARED_LIBS option (undefined by default) can be used to force shared/static build
option(CPPUTESTS_BUILD_TESTS "Build cppUTests tests" OFF)
option(CPPUTESTS_BUILD_EXAMPLES "Build cppUTests examples" OFF)
option(CPPUTESTS_BUILD_DOCS "Build cppUTests documentation" OFF)
option(CPPUTESTS_INSTALL "Generate target for installing cppUTests" ${is_top_level})
set_if_undefined(CPPUTESTS_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/cppUTests" CACHE STRING
    "Install path for cppUTests package-related CMake files")

if(DEFINED CPPUTESTS_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${CPPUTESTS_SHARED_LIBS})
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_if_undefined(CMAKE_CXX_VISIBILITY_PRESET hidden)
set_if_undefined(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

add_library(cppUTests) # initialized below
add_library(cppUTests::cppUTests ALIAS cppUTests)

#----------------------------------------------------------------------------------------------------------------------
# cppUTests dependencies
#----------------------------------------------------------------------------------------------------------------------

# Search for your dependencies here

#----------------------------------------------------------------------------------------------------------------------
# cppUTests sources
#----------------------------------------------------------------------------------------------------------------------

include(GenerateExportHeader)
set(export_file_name "export_shared.hpp")

if(NOT BUILD_SHARED_LIBS)
    set(export_file_name "export_static.hpp")
endif()

generate_export_header(cppUTests EXPORT_FILE_NAME include/cppUTests/${export_file_name})

set(sources
    include/cppUTests/export.hpp
    include/cppUTests/cppUTests.hpp
    include/cppUTests/implementations.hpp
    include/cppUTests/utility.hpp
    src/implementations.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

#----------------------------------------------------------------------------------------------------------------------
# cppUTests target
#----------------------------------------------------------------------------------------------------------------------

include(CMakePackageConfigHelpers)

target_sources(cppUTests PRIVATE ${sources})
target_compile_definitions(cppUTests PUBLIC "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:CPPUTESTS_STATIC_DEFINE>")

target_include_directories(cppUTests
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>")

set_target_properties(cppUTests PROPERTIES
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
    CXX_STANDARD 17
    CXX_EXTENSIONS ON)

if(CPPUTESTS_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    configure_package_config_file(cmake/cppUTests-config.cmake.in cppUTests-config.cmake
        INSTALL_DESTINATION "${CPPUTESTS_INSTALL_CMAKEDIR}")

    write_basic_package_version_file(cppUTests-config-version.cmake
        COMPATIBILITY SameMajorVersion)

    install(TARGETS cppUTests EXPORT CPPUTESTS_export
        RUNTIME COMPONENT cppUTests
        LIBRARY COMPONENT cppUTests NAMELINK_COMPONENT cppUTests-dev
        ARCHIVE COMPONENT cppUTests-dev
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
    install(DIRECTORY include/
        TYPE INCLUDE
        COMPONENT cppUTests-dev)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/cppUTests/${export_file_name}"
        COMPONENT cppUTests-dev
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/cppUTests")

    set(targets_file "cppUTests-shared-targets.cmake")

    if(NOT BUILD_SHARED_LIBS)
        set(targets_file "cppUTests-static-targets.cmake")
    endif()

    install(EXPORT CPPUTESTS_export
        COMPONENT cppUTests-dev
        FILE "${targets_file}"
        DESTINATION "${CPPUTESTS_INSTALL_CMAKEDIR}"
        NAMESPACE cppUTests::)

    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cppUTests-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cppUTests-config-version.cmake"
        COMPONENT cppUTests-dev
        DESTINATION "${CPPUTESTS_INSTALL_CMAKEDIR}")

    if(MSVC)
        set(pdb_file "")
        set(pdb_file_destination "")

        if(BUILD_SHARED_LIBS)
            set(pdb_file "$<TARGET_PDB_FILE:cppUTests>")
            set(pdb_file_destination "${CMAKE_INSTALL_BINDIR}")
        else()
            # TARGET_PDB_FILE does not work for pdb file generated for static library build, determining it manually
            set(pdb_file "$<TARGET_FILE_DIR:cppUTests>/$<TARGET_FILE_PREFIX:cppUTests>$<TARGET_FILE_BASE_NAME:cppUTests>.pdb")
            set(pdb_file_destination "${CMAKE_INSTALL_LIBDIR}")
        endif()

        install(FILES "${pdb_file}"
            COMPONENT cppUTests-dev
            CONFIGURATIONS Debug RelWithDebInfo
            DESTINATION "${pdb_file_destination}"
            OPTIONAL)
    endif()
endif()

#----------------------------------------------------------------------------------------------------------------------
# other targets
#----------------------------------------------------------------------------------------------------------------------

if(CPPUTESTS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(CPPUTESTS_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(CPPUTESTS_BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    doxygen_add_docs(docs include)
endif()
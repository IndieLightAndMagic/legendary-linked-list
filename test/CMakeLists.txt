cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

#Project Name and Resources 
set(TARGET_NAME nodetest)

project(${TARGET_NAME})

#DEBUG
set(CMAKE_VERBOSE_MAKEFILE ON)

#DIRECTORIES
get_filename_component(ROOT_DIR "../" ABSOLUTE)
set(INCLUDE_DIR "${ROOT_DIR}/inc")
set(LIB_ON_TEST_SOURCE_DIR "${ROOT_DIR}/src")
set(LIB_DIR "${ROOT_DIR}/lib")
message(STATUS "SYSTEM NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "ROOT_DIR: ${ROOT_DIR}")
message(STATUS "INCLUDE_DIR: ${INCLUDE_DIR}")
message(STATUS "LIBRARIAN DIR: ${LIB_DIR}")
message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "TEMPLATE_SOURCE_DIR: ${LIB_ON_TEST_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")

message(STATUS "-----------------------------")

#SOURCES: As this is a test for a templated class library we need to include as source code the library sources
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_LIST)
set (SOURCE_LIST ${SOURCE_LIST} "${LIB_ON_TEST_SOURCE_DIR}/node.cpp")

message(STATUS "Sources added to build target: ${TARGET_NAME}")
foreach (x ${SOURCE_LIST})
	message(STATUS ${x})
endforeach(x)

if (${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	add_executable(${TARGET_NAME} ${SOURCE_LIST})
elseif (${CMAKE_GENERATOR} STREQUAL "Xcode")
	add_executable(${TARGET_NAME} MACOSX_BUNDLE ${SOURCE_LIST} )
endif()


if (${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	message(STATUS "Unix Makefiles")
elseif(${CMAKE_GENERATOR} STREQUAL "Xcode")
	message(STATUS "Xcode")
endif()

#C++11
set(CPP11 "-std=c++11")
#MACRO DEFINITIONS
add_definitions(-DRES_DIR="${RES_DIR}")
#HEADER FILES
include_directories(${INCLUDE_DIR})
#COMPILE FLAGS
set(CMAKE_CXX_FLAGS "${CPP11}")
#LINKER
target_link_libraries(${TARGET_NAME} "${LIB_DIR}/libgtest.a")
	


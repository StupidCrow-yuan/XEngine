cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME XEngineMain)

project(${PROJECT_NAME})

set(EXE_NAME XEngineMain)

add_executable(${EXE_NAME})

add_subdirectory(Sandbox)

add_subdirectory(Xengine)

add_definitions("-DCPP_SRC_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\"")
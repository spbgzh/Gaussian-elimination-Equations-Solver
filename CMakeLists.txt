CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
set( CMAKE_CXX_FLAGS "-std=c++17" )

PROJECT(LinearAlgebraicEquationsSolver) 

FILE(GLOB main "${CMAKE_SOURCE_DIR}/*.cpp")
FILE(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
FILE(GLOB INCLUDE "${CMAKE_SOURCE_DIR}/include/*.hpp")

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include/")

ADD_EXECUTABLE(EquationsSolver ${main} ${SRC} ${INCLUDE})

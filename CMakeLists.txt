cmake_minimum_required(VERSION 3.22.1)
project(ODEsolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(ODEsolver main.cpp
        FunctionTree.h
        FunctionTree.cpp
        Parser.h
        Parser.cpp
        ODESolver.h
        ODESolver.cpp
        StringUtils.h
        StringUtils.cpp
)

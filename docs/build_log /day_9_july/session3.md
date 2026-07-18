# Build Log - Session 3

**Date:** July 10, 2026

## Objective
Refactor project into modular structure.

## Tasks Completed

- Separated declarations into .h files.
- Separated template definitions into .tpp files.
- Created:

include/
    linkedlist.h
    linkedlist.tpp
    vector.h
    vector.tpp

src/
    main.cpp

## CMake

Created CMakeLists.txt

Configured include directory.

Project now builds using:

cmake -S . -B build
cmake --build build

## Build Result

Executable generated successfully.

Verified execution.

## Notes

Template implementation is included through

#include "linkedlist.tpp"

inside linkedlist.h.
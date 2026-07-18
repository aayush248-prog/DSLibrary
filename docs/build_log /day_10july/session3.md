# Build Log – Session 3

**Date:** 10 July 2026
**Time:** 2:00 PM – 4:00 PM

## Objective
Research template compilation and modularize the data structure library.

## Work Completed

### Template Compilation Research
- Studied template instantiation.
- Understood why template definitions must be available during compilation.
- Researched the purpose of `.tpp` files.
- Learned why template implementations should not be placed inside separate `.cpp` files.

### Library Structure
- Organized the project into:
  - include/
  - src/
  - build/
  - docs/

### Refactoring
- Separated declarations and implementations.
- Planned conversion of:
  - LinkedList
  - HashMap
  - Vector

into reusable header-only template libraries.

### Build System Research
- Explored CMake project organization.
- Learned about include directories and target linking.
- Studied out-of-source builds.

## Outcome
- Defined the project architecture.
- Prepared the codebase for modular compilation using CMake.
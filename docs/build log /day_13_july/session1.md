# Build Log – Session 1

**Date:** 13 July 2026  
**Time:** 10:00 AM – 11:00 AM

## Objective
Refactor custom C++ data structures into a reusable and modular library.

## Work Completed

### Project Organization
- Organized the project into a standard library structure:
  - `include/`
  - `src/`
  - `build/`
  - `docs/`

### LinkedList Refactoring
- Separated the `LinkedList` implementation into:
  - `List.h`
  - `List.tpp`
- Moved all template implementations into the `.tpp` file.
- Included the implementation file inside the header.

### Memory Management
Implemented the Rule of Three:
- Copy Constructor
- Copy Assignment Operator
- Destructor

Ensured proper allocation and deallocation of dynamically allocated nodes.

### CMake Integration
- Configured the project to locate headers from the `include` directory.
- Verified successful compilation after modularization.

## Challenges
- Managing template definitions across multiple files.
- Ensuring template implementations were visible during compilation.

## Outcome
- Successfully converted the LinkedList into a reusable template library.
- Project compiled successfully after restructuring.
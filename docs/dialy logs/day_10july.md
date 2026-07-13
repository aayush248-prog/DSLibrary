# Daily Development Log

**Date:** 10 July 2026

## Working Hours
**10:00 AM – 6:30 PM**

---

# Objective

The primary objective for today's development was to design and implement a reusable C++ Data Structures Library with a focus on a generic **HashMap** implementation. Alongside implementation, research was conducted on hash table internals, template compilation, project modularization, memory management, and build system configuration using **CMake**.

---

# Session 1 (10:00 AM – 11:00 AM)

## Research and Planning

### Hash Table Research
- Studied the architecture of hash tables.
- Understood bucket-based storage.
- Compared collision resolution techniques:
  - Separate Chaining
  - Open Addressing
- Chose **Separate Chaining** for the implementation.

### Hash Function Research
- Explored hashing techniques for:
  - Integer keys
  - Character keys
  - String keys
  - User-defined objects
- Designed a generic hashing interface supporting custom `formhash()` implementations.

### Initial Design
- Planned the internal bucket structure.
- Designed the generic `Node<K,V>` structure.
- Planned automatic rehashing based on load factor.

### Outcome
- Finalized the architecture of the generic HashMap.
- Established the hashing strategy for primitive and custom data types.

---

# Session 2 (11:00 AM – 1:00 PM)

## HashMap Implementation

### Core Features
Implemented the following operations:

- Insert
- Find
- Remove
- Operator[]
- Dynamic bucket allocation

### Collision Handling
- Implemented Separate Chaining using linked lists.
- Verified insertion into existing buckets.
- Added duplicate key handling.

### Dynamic Rehashing
- Implemented load factor calculation.
- Added automatic bucket resizing.
- Reinserted existing elements after resizing.

### Research
- Studied average and worst-case complexities of:
  - Insert
  - Search
  - Delete
- Analysed the effect of load factor on HashMap performance.

### Outcome
- Completed the core implementation of the generic HashMap.

---

# Session 3 (2:00 PM – 4:00 PM)

## Template Library and Build System

### Template Compilation Research
Studied:
- Template instantiation
- Why template implementations cannot be compiled separately
- Purpose of `.tpp` files
- Header-only template libraries
- Common linker errors in template programming

### Project Modularization
Refactored the project into:

```
dslibrary/
├── include/
├── src/
├── build/
├── docs/
```

Separated implementations into:
- `.h`
- `.tpp`

### CMake Research
Explored:
- Include directories
- Source organization
- Out-of-source builds
- Header-only template compilation
- Target configuration

### Outcome
- Successfully organized the project into a reusable library structure.
- Prepared the project for modular compilation.

---

# Session 4 (4:00 PM – 6:30 PM)

## Integration and Validation

### Memory Management
Reviewed and implemented:

- malloc()
- Placement new
- Explicit destructor calls
- free()

Ensured proper cleanup of dynamically allocated memory.

### Copy Semantics
Implemented and verified:

- Copy Constructor
- Copy Assignment Operator
- Destructor

for custom containers.

### Build Integration
- Integrated all modules into the CMake build.
- Verified include hierarchy.
- Tested compilation of template-based classes.

### Debugging
Investigated:

- Template compilation issues
- HashMap lookup logic
- Bucket indexing
- Rehash behaviour
- Memory cleanup during resizing

### Validation
Performed initial testing of:

- HashMap
- LinkedList
- Vector

Verified:
- Object insertion
- Element retrieval
- Deep copying
- Dynamic memory cleanup

### Outcome
- Successfully integrated the data structure modules into the project.
- Identified remaining improvements for custom object hashing and additional testing.

---

# Research Conducted

## Data Structures
- Hash Table Architecture
- Collision Resolution
- Separate Chaining
- Dynamic Rehashing
- Load Factor Optimization

## C++ Concepts
- Generic Programming
- Template Instantiation
- Template Implementation Files (`.tpp`)
- Rule of Three
- Placement New
- Manual Memory Management

## Build System
- CMake Project Structure
- Header-only Libraries
- Include Directories
- Build Configuration
- Out-of-source Compilation

---

# Challenges Faced

- Designing a generic hashing mechanism for user-defined objects.
- Understanding template compilation across translation units.
- Organizing template implementations into reusable modules.
- Managing dynamic memory during rehashing.
- Integrating multiple template libraries into a single CMake project.

---

# Achievements

- Designed and implemented a generic HashMap.
- Implemented collision handling using Separate Chaining.
- Added automatic rehashing based on load factor.
- Organized the project into a modular C++ library.
- Configured the project using CMake.
- Improved understanding of template compilation and generic programming.
- Implemented proper memory management and deep copy semantics.

---

# Next Steps

- Improve HashMap performance.
- Enhance hashing support for complex user-defined types.
- Add comprehensive unit tests.
- Expand the library with additional STL-like containers.
- Improve documentation and usage examples.
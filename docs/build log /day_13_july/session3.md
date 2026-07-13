# Build Log – 13 July 2026

## Project
DSLibrary – Custom C++ Data Structures Library

---

# Session 3 (2:00 PM – 4:00 PM)

## Objective
Continue the implementation of the custom HashMap template and improve its internal design.

### Tasks Completed

- Implemented the generic `Hashcode` class for hashing multiple key types.
- Added overloads for:
  - `int`
  - `char`
  - `string`
  - User-defined classes through `formhash()`.
- Used C++20 `requires` expressions for compile-time detection of user-defined hash functions.
- Added compile-time validation using `static_assert` for unsupported key types.
- Implemented the `HashNode<K,V>` template.
- Implemented comparison operators for `HashNode`.
- Completed the basic `HashMap` structure.
- Implemented:
  - `push()`
  - `find()`
  - `pop()`
  - `operator[]`
- Added automatic insertion of default values inside `operator[]`.
- Implemented load factor tracking.
- Added automatic `rehash()` when the load factor exceeds `0.75`.

### Research

- Hash function design principles.
- Collision handling using separate chaining.
- Why bucket count (`Size`) should be used instead of vector capacity.
- Load factor calculation.
- Dynamic resizing strategies in hash tables.
- Importance of recomputing bucket indices after rehashing.

### Challenges

- Incorrect bucket index calculation.
- Using vector capacity instead of the active bucket count.
- Understanding how rehashing changes bucket positions.

### Outcome

Successfully completed the core functionality of the custom HashMap with automatic resizing.

---

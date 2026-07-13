# Daily Log – 14 July 2026

**Intern:** Aayush Sharma  
**Date:** 14 July 2026  
**Working Hours:** 2:00 PM – 6:00 PM (4 Hours)

---

## Objective

Continue the development of the custom C++ Data Structures Library by improving the `HashMap` implementation, implementing deep copy semantics, and restructuring the project into a modular template-based architecture.

---

## Work Completed

### 1. HashMap Development

- Continued implementation of the generic `HashMap<K, V>` template class.
- Implemented hashing support for:
  - `int`
  - `char`
  - `string`
  - User-defined objects using the `formhash()` interface.
- Reviewed bucket indexing logic.
- Corrected hash indexing to use the total number of buckets (`Size()`) instead of vector capacity.
- Verified insertion, searching, deletion, and element access operations.

---

### 2. Rehashing Implementation

- Reviewed load factor calculation.
- Improved the `rehash()` function.
- Reallocated buckets during resizing.
- Reinserted existing elements into newly created buckets.
- Verified that all elements remain accessible after rehashing.

---

### 3. Copy Semantics

- Implemented the `HashMap` copy constructor.
- Implemented the copy assignment operator.
- Reviewed self-assignment protection.
- Studied deep copy versus shallow copy in custom container classes.
- Reviewed Rule of Three concepts for resource-owning classes.

---

### 4. Template Library Refactoring

- Separated declarations and implementations into:
  - `HashMap.h`
  - `HashMap.tpp`
- Moved all template member function definitions into the `.tpp` file.
- Updated header files to include template implementations.

---

### 5. Project Structure

- Reorganized the project directory structure.
- Updated include paths after restructuring.
- Reviewed CMake configuration.
- Verified template file organization for reusable C++ libraries.

---

### 6. Debugging

- Investigated template compilation errors.
- Resolved missing template declaration issues.
- Fixed include-order problems.
- Improved const-correctness by updating linked list traversal functions.
- Verified copy constructor compatibility with const objects.

---

## Research Conducted

- Difference between `Size()` and `Capacity()` in custom containers.
- Bucket indexing strategy in hash table implementations.
- Hash table resizing and load factor management.
- Deep copy versus shallow copy.
- Rule of Three in C++.
- Template compilation model.
- Organization of template classes using `.h` and `.tpp` files.
- Const member functions and const-correct API design.
- Best practices for modular C++ library development.

---

## Challenges Faced

- Template compilation errors after separating implementation into `.tpp` files.
- Missing template declarations before including implementation files.
- Const-correctness issues while copying linked list nodes.
- Include path errors after reorganizing the project structure.

---

## Solutions Implemented

- Added proper class declarations in `HashMap.h`.
- Moved template definitions into `HashMap.tpp`.
- Updated include paths to match the new directory layout.
- Modified linked list traversal functions to support const objects.
- Verified copy constructor and assignment operator behavior.

---

## Outcome

- Successfully modularized the `HashMap` implementation.
- Improved understanding of template compilation and project organization.
- Implemented deep copy functionality for the custom hash map.
- Resolved multiple compilation and template-related issues.
- Created a cleaner and more maintainable project structure.

---

## Next Plan

- Complete testing of the `HashMap` implementation.
- Implement iterators for the hash map.
- Add utility functions:
  - `size()`
  - `empty()`
  - `clear()`
  - `contains()`
- Perform stress testing and memory leak analysis using AddressSanitizer.
- Continue expanding the custom C++ Data Structures Library.
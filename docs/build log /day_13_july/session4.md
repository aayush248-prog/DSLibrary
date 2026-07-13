# Session 4 (4:00 PM – 6:00 PM)

## Objective

Improve memory safety, implement copy semantics, and reorganize the project structure.

### Tasks Completed

- Implemented HashMap copy constructor.
- Corrected traversal to copy elements from the source object.
- Initialized internal members before copying.
- Implemented assignment operator.
- Added self-assignment protection.
- Verified deep copy behavior through the custom `Vector` implementation.
- Converted the HashMap implementation into:
  - `HashMap.h`
  - `HashMap.tpp`
- Moved template definitions from the header to the `.tpp` file.
- Reorganized the project into:
  - `include/`
  - `src/`
- Updated header inclusion strategy.
- Fixed template compilation issues.
- Corrected include dependencies between `.h` and `.tpp` files.
- Fixed const-correctness issues in `Linkedlist::begin()`.
- Added `const` overloads where required for compatibility with copy constructors.

### Research

- Template implementation separation using `.tpp` files.
- Why template implementations cannot be compiled separately.
- Header inclusion order.
- Copy constructor vs assignment operator.
- Deep copy vs shallow copy.
- Self-assignment handling.
- Const correctness in member functions.
- Organization of reusable template libraries.

### Debugging

Resolved multiple compiler errors including:

- Unknown template type errors.
- Missing class declarations.
- Incorrect include hierarchy.
- Missing template definitions.
- Const qualification errors.
- Copy constructor compilation failures.

### Outcome

Successfully modularized the HashMap implementation into reusable header and template files while resolving template compilation and const-correctness issues.

---

# Total Duration

**2:00 PM – 6:00 PM (4 Hours)**

---

# Skills Strengthened

- Advanced C++ Templates
- Generic Programming
- Compile-time Programming (C++20)
- Custom Hash Table Design
- Dynamic Rehashing
- Deep Copy Semantics
- Copy Constructor & Assignment Operator
- Const Correctness
- Header/Template File Organization
- CMake Project Structure
- Memory Management
- Template Library Design
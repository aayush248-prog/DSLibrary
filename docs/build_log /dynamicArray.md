# Build Log

**Date:** 06 July 2026  
**Project:** Generic Dynamic Array Documentation  
**Build Duration:** 6 Hours

---

## Build Session 1 (12:00 AM – 2:00 AM)

### Objective
Build the foundation for the project documentation by understanding Markdown syntax and documentation standards.

### Work Completed

- Studied the syntax and structure of **Markdown (.md)** files.
- Implemented different Markdown components, including:
  - Headings
  - Paragraphs
  - Ordered and unordered lists
  - Tables
  - Code blocks
  - Blockquotes
  - Horizontal rules
- Practiced writing technical documentation using Markdown.
- Learned how Markdown is rendered into readable project documentation.
- Implemented hyperlinks, inline code, images/images, and internal references.

### Build Outcome

- Successfully created the base documentation format for the project.
- Established a standardized documentation style to be followed throughout the project.

---

## Build Session 2 (2:00 AM – 6:00 AM)

### Objective
Develop the Design Proposal documentation for the Generic Dynamic Array.

### Work Completed

#### Documentation Structure

- Designed the documentation directory structure.
- Organized documentation into logical sections.
- Added internal navigation between sections.

#### Public API Documentation

Completed documentation for:

- `push_back()`
- `pop_back()`
- `size()`
- `empty()`

including:

- Function descriptions
- Parameters
- Return types
- Operational behavior

#### Internal Design Documentation

Documented:

- Internal data members
- Object-oriented implementation
- Class organization
- Memory layout

#### Memory Management

Prepared detailed documentation explaining:

- Dynamic memory allocation using `malloc()`
- Zero-initialized allocation using `calloc()`
- Memory deallocation using `free()`
- Heap memory management
- Pointer usage
- Dynamic resizing process

#### Design Decisions

Documented the major implementation decisions:

- Generic programming using **C++ Templates**
- Capacity doubling (**Resizing Factor = 2**)
- Use of contiguous memory
- Manual memory management strategy
- Selection of `malloc()`, `calloc()`, and `free()`

#### Rule of Three

Added complete documentation covering:

- Destructor
- Copy Constructor
- Copy Assignment Operator
- Deep Copy vs Shallow Copy
- Memory ownership
- Prevention of memory leaks and double-free errors

#### Time Complexity

Completed complexity analysis for:

- Insertion
- Deletion
- Search
- Random Access
- Amortized analysis of `push_back()`

Included explanations and memory diagrams wherever necessary.

### Build Outcome

- Successfully completed a comprehensive **Design Proposal** for the Generic Dynamic Array.
- Finalized documentation covering architecture, implementation details, memory management, design decisions, Rule of Three, and complexity analysis.
- Established a well-structured documentation framework that can be extended during future implementation phases.

---

# Build Summary

## Components Completed

- ✅ Markdown Documentation Structure
- ✅ Documentation Directory Organization
- ✅ Public API Documentation
- ✅ Internal Class Structure Documentation
- ✅ Memory Management Documentation
- ✅ Design Decisions
- ✅ Rule of Three Documentation
- ✅ Time Complexity Analysis
- ✅ Amortized Analysis
- ✅ Memory Diagrams and Technical Explanations

## Current Status

The documentation phase for the **Generic Dynamic Array Design Proposal** has been successfully completed. The project now contains a structured and maintainable design document that will serve as the reference for the implementation phase.
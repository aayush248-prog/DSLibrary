# Build Log – Session 2

**Date:** 13 July 2026  
**Time:** 11:00 AM – 12:00 PM

## Objective
Modularize and integrate the custom HashMap implementation.

## Work Completed

### HashMap Refactoring
- Split the HashMap implementation into:
  - `Hashmap.h`
  - `Hashmap.tpp`
- Moved template definitions into the `.tpp` file.
- Included the implementation file inside the header.

### Project Improvements
- Added namespaces for better code organization.
- Updated the CMake configuration for template-based modules.

### Conflict Resolution
- Identified naming conflicts between:
  - `LinkedList::Node`
  - `HashMap::Node`
- Renamed the linked list node class to `ListNode` to eliminate symbol conflicts.

### HashMap Testing
- Tested the HashMap using a custom `Student` class as the key.
- Added custom hashing support using the `formhash()` member function.
- Verified insertion and lookup operations.

### Debugging
- Investigated an issue where lookups returned default values (`0`) instead of stored values.
- Traced the problem through:
  - Hash generation
  - Bucket indexing
  - Template overload resolution
  - Key comparison logic

## Challenges
- Resolving template instantiation issues.
- Eliminating class name conflicts.
- Debugging custom object hashing.

## Outcome
- Successfully integrated the HashMap into the library structure.
- Template organization and project compilation are complete.
- Further debugging of custom key lookup is in progress.
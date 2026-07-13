# Build Log – Session 2

**Date:** 10 July 2026
**Time:** 11:00 AM – 1:00 PM

## Objective
Implement the core components of the generic HashMap.

## Work Completed

### HashMap Development
- Implemented the generic `Node<K,V>` class.
- Created the bucket array for storing linked lists.
- Implemented:
  - insert()
  - find()
  - pop()
  - operator[]

### Collision Handling
- Added Separate Chaining using linked lists.
- Verified insertion into existing buckets.
- Tested key comparison for duplicate entries.

### Dynamic Resizing
- Implemented load factor calculation.
- Added automatic rehashing when load factor exceeds the threshold.
- Reintegrated all existing elements during resizing.

## Research
- Studied time complexity of:
  - Insert
  - Search
  - Delete
- Analysed the impact of load factor on performance.

## Outcome
- Core HashMap functionality completed.
- Dynamic resizing mechanism implemented successfully.
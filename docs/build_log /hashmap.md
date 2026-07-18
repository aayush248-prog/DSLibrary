# Build Log

**Project:** Generic HashMap Implementation in C++  
**Date:** July 8, 2026  
**Duration:** 2 Hours

---

# Objective

The objective of this research session was to understand the internal working of a HashMap, study the design decisions required for implementing a generic HashMap in C++, and identify suitable approaches for handling different key types, collisions, memory allocation, and dynamic resizing.

---

# Session Timeline

## 00:00 – 00:20 | Understanding HashMap Fundamentals

### Research Activities

- Studied the internal architecture of a HashMap.
- Learned how key-value pairs are stored.
- Explored the role of bucket arrays.
- Understood why hashing is required for constant-time lookup.

### Observations

A HashMap stores data inside a bucket array. Each key is converted into an index using a hash function, allowing direct access to the corresponding bucket. Since multiple keys may map to the same index, a collision resolution strategy is required.

### Decisions

- Use a bucket array as the primary storage.
- Store linked list heads inside each bucket.

---

## 00:20 – 00:40 | Memory Management Strategy

### Research Activities

- Compared `new`, `malloc()`, and `calloc()`.
- Researched how bucket arrays are initialized.
- Studied node allocation techniques.

### Observations

Using `calloc()` automatically initializes all bucket pointers to `NULL`, making initialization easier. Individual nodes can then be allocated using `malloc()` as new elements are inserted.

### Decisions

- Allocate bucket arrays using `calloc()`.
- Allocate linked list nodes using `malloc()`.

---

## 00:40 – 01:00 | Collision Resolution

### Research Activities

- Explored different collision handling techniques.
  - Separate Chaining
  - Linear Probing
  - Quadratic Probing
  - Double Hashing
- Compared their advantages and disadvantages.

### Observations

Separate Chaining is simple to implement and allows multiple elements to exist in the same bucket by linking them together using a singly linked list.

### Decisions

- Implement Separate Chaining using linked lists.

---

## 01:00 – 01:20 | Load Factor and Rehashing

### Research Activities

- Studied how HashMaps maintain performance as data grows.
- Learned about load factor calculation.
- Investigated when rehashing should occur.

### Observations

The load factor is calculated as:

```
Load Factor = Number of Stored Elements / Number of Buckets
```

As the load factor increases, collisions become more frequent. To reduce collisions, the bucket array should be resized and all existing elements should be reinserted using new hash values.

### Decisions

- Maintain a load factor threshold of **0.75**.
- Double the bucket array size whenever the threshold is exceeded.
- Rehash every stored element after resizing.

---

## 01:20 – 01:40 | Generic Hash Function Design

### Research Activities

- Explored hashing for different key types.
- Implemented hash functions for integers, characters, and strings.
- Investigated how user-defined objects can be used as keys.
- Explored whether object addresses or object sizes could be used for hashing.

### Observations

- Integer keys can be hashed using the modulo operator.
- Character keys are also numeric and can use modulo.
- String keys require converting the string into an integer value before applying modulo.
- Using an object's memory address is not reliable because identical objects stored at different locations produce different hash values.
- Using `sizeof()` is also unsuitable because all objects of the same type generally have the same size.
- C++ cannot automatically determine which data members should participate in hashing for an arbitrary user-defined class.

### Decisions

- Provide specialized hash functions for built-in types.
- Require user-defined classes to provide their own hashing logic (e.g., a `hashCode()` function or a custom hash functor).

---

## 01:40 – 02:00 | Final Architecture Planning

### Research Activities

- Designed the overall HashMap class structure.
- Planned bucket representation and linked list integration.
- Designed insertion, search, and rehash workflows.
- Reviewed how templates support generic programming.

### Observations

The final implementation will consist of:

- Template-based HashMap class.
- Template-based Node class.
- Bucket array storing linked list heads.
- Generic hash function interface.
- Dynamic rehashing.
- Separate chaining for collision resolution.

### Decisions

Finalized the architecture before implementation.

---

# Key Learnings

- Internal architecture of a HashMap.
- Bucket array organization.
- Collision resolution techniques.
- Separate Chaining implementation.
- Dynamic memory allocation using `calloc()` and `malloc()`.
- Load factor calculation.
- Rehashing process.
- Generic programming using C++ templates.
- Challenges of hashing user-defined classes.
- Importance of designing flexible hash functions.

---

# Challenges Faced

| Challenge | Resolution |
|-----------|------------|
| Designing a generic hash function | Studied specialized hash functions and custom hashing strategies. |
| Supporting user-defined objects | Decided to require user-defined hashing logic. |
| Managing collisions efficiently | Selected Separate Chaining. |
| Resizing the table without data loss | Planned a complete rehashing process. |

---

# Design Decisions

- Use templates for generic implementation.
- Allocate bucket arrays using `calloc()`.
- Allocate nodes using `malloc()`.
- Use Separate Chaining for collision handling.
- Maintain a load factor threshold of **0.75**.
- Double the bucket array size during rehashing.
- Support primitive key types with dedicated hash functions.
- Allow user-defined classes by requiring custom hashing logic.

---

# Technologies / Concepts Explored

- C++ Templates
- Generic Programming
- Dynamic Memory Allocation
- malloc()
- calloc()
- Bucket Arrays
- Linked Lists
- Hash Functions
- Collision Resolution
- Separate Chaining
- Load Factor
- Rehashing

---

# Outcome

By the end of this research session, the overall architecture of the custom HashMap was finalized. A clear understanding was developed regarding bucket organization, memory allocation, collision handling, dynamic resizing, and hashing strategies for different key types. The limitations of hashing arbitrary user-defined objects were also identified, leading to the decision to require custom hashing logic for such types. These findings provide a solid foundation for implementing insertion, search, deletion, and rehashing functionalities.

---

# Next Steps

- [ ] Implement insertion.
- [ ] Complete the rehashing algorithm.
- [ ] Implement search operation.
- [ ] Implement deletion operation.
- [ ] Add traversal functionality.
- [ ] Test with integer, string, and custom object keys.
- [ ] Evaluate performance under different load factors.

---

# Time Summary

| Activity | Duration |
|----------|----------|
| HashMap Architecture Research | 20 min |
| Memory Management Research | 20 min |
| Collision Handling Research | 20 min |
| Load Factor & Rehashing | 20 min |
| Generic Hash Function Research | 20 min |
| Final Design Planning | 20 min |
| **Total** | **2 Hours** |
# HashMap Design Proposal

## Overview

This document describes the design of a generic `HashMap<K, V>` implemented using templates in C++. The implementation stores key-value pairs using **separate chaining** with singly linked lists. Dynamic memory allocation is performed using `calloc()` for the bucket array and `malloc()` for individual nodes.

---

## Class Structure

### Node

```cpp
template<typename K, typename V>
class Node
{
public:
    K key;
    V val;
    Node<K,V>* next;
};
```

Each node stores:
- **key**: unique identifier
- **val**: associated value
- **next**: pointer to the next node.

---

### HashMap Members

```cpp
Node<K,V>** bucket;
int size;
int lst_count;
float load_factor;
```

- `bucket`: Array of bucket pointers.
- `size`: Number of buckets.
- `lst_count`: Number of stored key-value pairs.
- `load_factor`: Ratio of elements to buckets.

---

## Memory Layout

```
Bucket Array

0 -> NULL
1 -> NULL
2 -> NULL
3 -> NULL
...
```

Collision example:

```
Bucket 2

↓

(12,A)

↓

(22,B)

↓

(42,C)

↓

NULL
```

---

## Constructor

```cpp
Hashmap(int size)
```

Responsibilities:

- Allocate the bucket array using `calloc()`
- Initialize all bucket pointers to `NULL`
- Store the bucket count
- Initialize `lst_count` and `load_factor`

---

## Hash Function

```cpp
int hash(K key)
{
    return key % size;
}
```

Example:

```
Key = 27
Buckets = 10

27 % 10 = 7
```

---

## Insertion

Algorithm:

1. Compute load factor.
2. If load factor exceeds 0.75, call `rehash()`.
3. Allocate a node using `malloc()`.
4. Compute bucket index.
5. Insert into the appropriate linked list.

Average complexity: **O(1)**

Worst case: **O(n)**

---

## Collision Resolution

Separate chaining stores multiple elements in the same bucket.

```
Bucket 5

↓

(5,X)

↓

(15,Y)

↓

(25,Z)
```

---

## Load Factor

```
Load Factor = Number of Elements / Number of Buckets
```

When the load factor exceeds **0.75**, the table is resized.

---

## Rehashing

Steps:

1. Store the previous bucket array.
2. Double the bucket count.
3. Allocate a new bucket array.
4. Traverse each linked list.
5. Recompute bucket indices.
6. Reinsert elements.
7. Free the previous bucket array.

---

## Time Complexity

| Operation | Average | Worst |
|-----------|---------|--------|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |
| Rehash | O(n) | O(n) |

---

## Design Decisions

- Generic implementation using templates.
- Separate chaining for collision handling.
- Dynamic resizing through rehashing.
- Manual memory management using `calloc()` and `malloc()`.
- Modulo-based hash function for integer keys.

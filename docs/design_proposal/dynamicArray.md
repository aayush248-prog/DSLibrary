# Public API

A **dynamic array** is a data structure whose size can grow or shrink during program execution. Unlike a static array, a dynamic array automatically allocates more memory when its current capacity is exhausted.

The public API provides the functions that users can call to perform common operations such as insertion, deletion, searching, and querying the state of the dynamic array.
**WE ARE IMPLEMENTING FOR GENERIC POINT OF VIEW**
## Functions

### `push_back(T element)`

- Inserts a new element at the **end** (rear) of the dynamic array.
- If the array has reached its capacity, a larger block of memory is allocated, the existing elements are copied to the new memory, and the new element is appended.
- **Parameter:**
  - `element` (`T`): The value to be inserted.
- **Return Type:**
  - `void`

---

### `size()`

- Returns the current number of elements stored in the dynamic array.
- Does not take any parameters.
- **Return Type:**
  - `int`

---

### `empty()`

- Checks whether the dynamic array contains any elements.
- Internally, it verifies whether the current size of the array is equal to zero.
- Returns `true` if the array is empty; otherwise, returns `false`.
- Does not take any parameters.
- **Return Type:**
  - `bool`

---

### `pop_back()`

- Removes the last element from the dynamic array.
- If the array is already empty, no element is removed.
- Does not take any parameters.
- **Return Type:**
  - `void`

---

#### **INTERNAL STRUCTURE:**
A internal structure of the dynamic array is the most important as it contains the implementations of the **DATASTRUCTURE**. so all the implementations are primarily made of **OBJECT ORIENTED PROGRAMMING MODEL** because it helps to effectively implements the function and also provides the concepts of encapsulation,abstraction,overloading,destructors,constructors.

So  class basically consists of value and their accesfiers and their encapsulated version is called a **Class**.

-***Values***
-Size
-Capacity
-pointer
-***Functions***
They are the Functions already explained in the funtions api [Functions]

---
-***MEMORY MANAGEMENT IN DYNAMIC ARRAY**
So basically in simple static array we find some problems like.
 -***fixed size***
 It is the main or the critical problem which programmers feel  when they use the dynamic array.
 Let is take an example that if a client is entering the data but  due to insufficient memory the data is lost so that data is is missed by the server so that can not be computed further so  companies who provides services like live streams.
 So the concept of dynamic arrays come into picture.

---***MEMORY MANAGEMENT IN CPP***  
So cpp is a near to memory type of programming language which provide us the memory access using pointers.Pointer are the variables which store a address in it the size of the address depends on the system configurations.

---***FUNCTIONS FOR THE MEMORY MANAGEMENT IN CPP***
 -`malloc(n*sizeof(T))`
 -This is the primary function of the memory allocation in cpp.
 - Here **n** represents the multiplicity of the size and **sizeof (T)** represents the size of the single unit of that datatype.
 -So combined representaion shows the total size required to store  the value of the given datatype in the contiguous memory.
 -The return type is the void pointer.
 -It only allocated the memory but don't initialize it.
 -***Return Type*** 
 -`void*`
 **NOTE:This memory is allocated in the heap not int the stack.**
 -`calloc(no of elements,sizeof(T))`
  -It is similar two **malloc()** but needs two parameters in it.
  -It also initialize te memory withe value of the zero.
  -It's return type is also void.
  -**RETURN TYPE**
   -`void*`
 -`free(ptr)`
  -It is the function used to free the reserved memory used by the program during execution.
  -It is the important function as it rduces the chances of **memory leak** and **Dangling Pointer**.
## Dynamic Array Implementation

A dynamic array stores its elements in a contiguous block of memory. Unlike a static array, it can increase its storage capacity whenever the current capacity is exhausted.

### Resizing Strategy

When

```
size == capacity
```

the array cannot accommodate any more elements. The following steps are performed:

1. Allocate a new block of memory with a larger capacity.
2. Copy (or move) all existing elements into the new memory.
3. Release the previously allocated memory.
4. Update the internal pointer to point to the new memory block.
5. Insert the new element.

### Choosing the Growth Factor

One of the most important design decisions is choosing the new capacity.

A growth factor that is too small causes frequent reallocations, increasing the cost of insertions.

A growth factor that is too large wastes memory.

The most commonly used strategy is

```
new_capacity = 2 × old_capacity
```

This doubling strategy provides **amortized O(1)** time complexity for `push_back()` while keeping the number of reallocations relatively small.

Some implementations use a growth factor of **1.5×** to reduce memory overhead.

### Alternative Approach: Exponential Moving Average (EMA)

Instead of using a fixed growth factor, one could estimate the future storage requirement using an **Exponential Moving Average (EMA)** based on previous growth patterns.

The predicted capacity could then be used to allocate memory more intelligently.

Although this approach may reduce unused memory in certain workloads, it introduces additional computation and does not provide the same theoretical guarantees as geometric resizing. Therefore, standard dynamic arrays generally prefer fixed growth factors such as 1.5× or 2×.

This idea can be explored as an experimental or research-oriented project rather than a production implementation.ed as a good learning project.

-**INTERNAL REPRESENTATION** 
![DYNAMIC ARRAY](/docs/design_proposal/images/ChatGPT%20Image%20Jul%206,%202026,%2003_44_06%20PM.png)
---
# Time Complexity Analysis of Dynamic Array

The performance of a dynamic array depends on the operation being performed. While accessing an element using its index is very efficient, operations that require shifting elements or resizing the array may take more time.

## Time Complexity Table

| Operation | Front | Middle | End (Rear) |
|-----------|:-----:|:------:|:----------:|
| Insertion | **O(n)** | **O(n)** | **O(1)** *(Amortized)* |
| Deletion | **O(n)** | **O(n)** | **O(1)** |
| Search (Linear) | **O(n)** | **O(n)** | **O(n)** |
| Access by Index | **O(1)** | **O(1)** | **O(1)** |

---

## Insertion

### 1. Insertion at the Front

**Time Complexity:** `O(n)`

When an element is inserted at the beginning of the array, every existing element must be shifted one position to the right.

Example:

Before

```text
[10][20][30][40]
```

Insert `5`

After

```text
[5][10][20][30][40]
```

Since all elements are shifted, the time complexity is **O(n)**.

---

### 2. Insertion in the Middle

**Time Complexity:** `O(n)`

To insert an element at any intermediate position, all elements after that position are shifted one place to the right.

Example:

Before

```text
[10][20][40][50]
```

Insert `30`

After

```text
[10][20][30][40][50]
```

The shifting operation makes the complexity **O(n)**.

---

### 3. Insertion at the End (`push_back()`)

**Time Complexity:** `O(1)` *(Amortized)*

Normally, the new element is simply placed after the last element.

Example

```text
[10][20][30]
```

Insert `40`

```text
[10][20][30][40]
```

However, if the array is full (`size == capacity`), a new larger memory block is allocated and all existing elements are copied.

This resizing operation takes **O(n)** time.

Since resizing happens infrequently, the average (amortized) complexity of `push_back()` remains **O(1)**.

---

## Deletion

### 1. Deletion from the Front

**Time Complexity:** `O(n)`

After deleting the first element, every remaining element must shift one position to the left.

Example

Before

```text
[10][20][30][40]
```

Delete `10`

After

```text
[20][30][40]
```

Therefore, the complexity is **O(n)**.

---

### 2. Deletion from the Middle

**Time Complexity:** `O(n)`

Deleting an element from the middle requires shifting all subsequent elements one position to the left.

Example

Before

```text
[10][20][30][40][50]
```

Delete `30`

After

```text
[10][20][40][50]
```

Hence, the complexity is **O(n)**.

---

### 3. Deletion from the End (`pop_back()`)

**Time Complexity:** `O(1)`

The last element is removed by simply decreasing the size of the array.

Example

Before

```text
[10][20][30][40]
```

Delete `40`

After

```text
[10][20][30]
```

No shifting is required, so the complexity is **O(1)**.

---

## Searching

### Linear Search

**Time Complexity:** `O(n)`

If the array is unsorted, every element may need to be examined until the desired element is found.

Example

```text
[10][20][30][40][50]
```

Searching for `50` may require checking all five elements.

Therefore, the worst-case complexity is **O(n)**.

---

### Binary Search (Sorted Dynamic Array)

If the elements are stored in sorted order, Binary Search can be applied.

**Time Complexity:** `O(log n)`

> **Note:** Binary Search is only applicable when the dynamic array is sorted.

---

## Accessing Elements

### Random Access using Index

**Time Complexity:** `O(1)`

Dynamic arrays store their elements in contiguous memory locations.

The address of the required element is computed using

```
Address = Base Address + (Index × Size of Data Type)
```

Therefore, accessing any element by its index requires constant time.

Example

```cpp
arr[25]
```

is performed in **O(1)** time regardless of the size of the array.

---

## Summary

| Operation | Best Case | Average Case | Worst Case |
|-----------|:---------:|:------------:|:----------:|
| Access | O(1) | O(1) | O(1) |
| Search | O(1) | O(n) | O(n) |
| Insert at Front | O(n) | O(n) | O(n) |
| Insert at Middle | O(n) | O(n) | O(n) |
| Insert at End | O(1) | O(1) *(Amortized)* | O(n) *(During Resizing)* |
| Delete from Front | O(n) | O(n) | O(n) |
| Delete from Middle | O(n) | O(n) | O(n) |
| Delete from End | O(1) | O(1) | O(1) |
---
# Design Decisions

While implementing the dynamic array, several design decisions were made to ensure that the implementation remains simple, efficient, and generic. These decisions influence the memory management strategy, resizing mechanism, and the overall flexibility of the data structure.

---

## 1. Generic Programming using Templates

The dynamic array is implemented using **C++ templates**.

```cpp
template <typename T>
class Vector
{
    ...
};
```

Using templates allows the same implementation to work with different data types without rewriting the code.

### Advantages

- Supports any user-defined or primitive data type.
- Eliminates code duplication.
- Type-safe implementation.
- Compile-time polymorphism.

For example,

```cpp
Vector<int> v1;
Vector<double> v2;
Vector<string> v3;
```

All three objects use the same implementation.

---

## 2. Memory Allocation Strategy

The implementation uses the C standard library memory allocation functions.

### `malloc()`

Used to allocate a contiguous block of memory.

```cpp
ptr = (T*)malloc(capacity * sizeof(T));
```

Characteristics:

- Allocates memory on the **Heap**.
- Returns a `void*`.
- Does **not** initialize the allocated memory.
- Time Complexity: **O(1)**

---

### `calloc()`

Used whenever zero-initialized memory is required.

```cpp
ptr = (T*)calloc(capacity, sizeof(T));
```

Characteristics:

- Allocates memory on the **Heap**.
- Initializes every byte with zero.
- Returns a `void*`.
- Time Complexity: **O(n)** (initialization cost)

---

### `free()`

Used to release dynamically allocated memory.

```cpp
free(ptr);
```

Characteristics:

- Prevents memory leaks.
- Releases heap memory back to the operating system.
- Used whenever the old memory block is no longer required after resizing.

---

## 3. Resizing Strategy

One of the most important design decisions in a dynamic array is deciding **how much additional memory should be allocated** when the array becomes full.

In this implementation, the capacity is doubled whenever

```
size == capacity
```

The resizing formula is

```
New Capacity = 2 × Old Capacity
```

Example

| Current Capacity | New Capacity |
|-----------------:|-------------:|
| 1 | 2 |
| 2 | 4 |
| 4 | 8 |
| 8 | 16 |
| 16 | 32 |

---

### Why choose a resizing factor of **2**?

Using a growth factor of **2** provides a good balance between memory usage and performance.

Advantages:

- Reduces the number of reallocations.
- Provides **Amortized O(1)** insertion at the end.
- Simple and efficient implementation.
- Minimizes the total number of element copies over multiple insertions.
- Commonly used in many dynamic array implementations.

Although a smaller growth factor (such as **1.5×**) may reduce unused memory, it increases the frequency of reallocations. On the other hand, a much larger growth factor wastes memory. Therefore, doubling the capacity offers a practical trade-off between performance and memory utilization.

---

## 4. Internal Data Members

The dynamic array maintains the following private data members.

```cpp
size_t size;
size_t capacity;
T* ptr;
```

| Variable | Purpose |
|----------|---------|
| `size` | Number of elements currently stored. |
| `capacity` | Total number of elements that can be stored before resizing is required. |
| `ptr` | Pointer to the dynamically allocated contiguous memory block. |

---

## 5. Memory Layout

```
               Stack

        +----------------------+
        | size = 5             |
        | capacity = 8         |
        | ptr -----------------|-------------------+
        +----------------------+                   |
                                                   |
                                                   ▼

                         Heap

        +----+----+----+----+----+----+----+----+
        |10  |20  |30  |40  |50  |    |    |    |
        +----+----+----+----+----+----+----+----+
```

The object stores only the metadata (`size`, `capacity`, and `ptr`) on the stack, while the actual elements are stored in a contiguous block of heap memory.

---

## Summary of Design Decisions

| Feature | Design Choice |
|---------|---------------|
| Generic Programming | C++ Templates (`template<typename T>`) |
| Memory Allocation | `malloc()` |
| Zero Initialization | `calloc()` |
| Memory Deallocation | `free()` |
| Growth Strategy | Capacity × 2 |
| Memory Storage | Heap |
| Metadata Storage | Stack |
| End Insertion Complexity | **O(1)** (Amortized) |
| Random Access | **O(1)** |




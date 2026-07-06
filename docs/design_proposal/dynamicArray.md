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





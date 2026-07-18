# Vector<T> Build Log

## Goal
Implement a generic `Vector<T>` similar to `std::vector` while learning low-level C++ memory management.

## Version 1
- Implemented:
  - `push_back()`
  - `pop_back()`
  - Dynamic resizing
- Used `malloc()` and `free()`.

### Issues
- Worked only for primitive types.
- No exception handling.
- No destructor.

---

## Version 2
### Added exception handling
- `std::underflow_error` in `pop_back()`
- `std::out_of_range` in `print()`

Example:

```cpp
throw underflow_error("under flow");
throw out_of_range("out of bound");
```

---

## Version 3
### Learned Placement New

Old:

```cpp
ptr[size] = x;
```

New:

```cpp
new(&ptr[size]) T(x);
```

Reason:
- `malloc()` allocates raw memory only.
- Placement new constructs the object in that memory.

---

## Version 4
### Fixed resizing

Old:

```cpp
ptr[i] = temp[i];
```

New:

```cpp
new(&ptr[i]) T(temp[i]);
```

Objects are copy-constructed into the new storage.

---

## Version 5
### Destructor

Added destruction of every constructed object before freeing memory.

```cpp
for(int i=0;i<size;i++)
    ptr[i].~T();

free(ptr);
```

---

## Remaining Fixes

### pop_back()

Current implementation should destroy the last object:

```cpp
ptr[size-1].~T();
size--;
```

---

### During resizing

Destroy old objects after copy construction:

```cpp
new(&ptr[i]) T(temp[i]);
temp[i].~T();
```

---

## Important Concepts Learned

### malloc()
- Allocates raw memory.
- Does NOT call constructors.

### free()
- Releases memory.
- Does NOT call destructors.

### new
- Allocates memory.
- Calls constructor.

### Placement new

```cpp
new(address) T(arguments);
```

- Uses existing memory.
- Calls constructor only.

### Explicit destructor

```cpp
ptr[i].~T();
```

Destroys an object without freeing its memory.

---

## Current Status

Implemented:
- Generic template
- Dynamic resizing
- Placement new
- Exception handling
- Destructor
- Support for `std::string`

Next improvements:
- Replace `malloc/free` with `::operator new` / `::operator delete`
- Copy constructor
- Copy assignment operator
- Move constructor
- Move assignment operator
- `reserve()`
- `capacity()`
- `operator[]`
- Iterator support

---

## Key Takeaways

1. Allocation and construction are different operations.
2. Placement new constructs objects in raw memory.
3. Every placement new must have a matching destructor call.
4. Generic containers must correctly manage object lifetimes.
5. These techniques are the foundation of `std::vector`.

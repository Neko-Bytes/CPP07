# C++ Module 07 - Templates

This project is part of the 42 curriculum completed by me (loginID:**kmummadi**).

This project introduces generic programming in C++ using function templates and class templates, compiled with C++17.

---

## Overview of Exercises

### `ex00`: Start with a few functions
Generic utility function templates implemented in `whatever.hpp`:
- `swap(a, b)`: Swaps the values of two variables.
- `min(a, b)`: Returns the smaller of two arguments (returns the second if equal).
- `max(a, b)`: Returns the larger of two arguments (returns the second if equal).

### `ex01`: Iter
A generic `iter` template in `iter.hpp` that applies a function or callable to each element of an array:
```cpp
template <typename T, typename F>
void iter(T *arr, const size_t len, F funct);
```
- Works with both mutable (`T*`) and read-only (`const T*`) arrays.
- Supports callables taking arguments by non-const or const reference (`T&` / `const T&`).

### `ex02`: Array
A generic dynamic array class template `Array<T>` in `Array.hpp`:
- Implemented in Orthodox Canonical Form (default constructor, sized constructor, copy constructor, assignment operator, destructor).
- Deep copy semantics to ensure copies remain independent.
- Memory allocation via `new[]` and deallocation via `delete[]`.
- Bounds-checked element access through `operator[]` (with both `const` and non-`const` overloads), throwing `std::out_of_range` on out-of-bounds index access.
- `size()` member function returning the element count.

---

## Building and Running

Each exercise directory contains a Makefile:

```bash
# Build and run ex00
cd ex00
make
./whatever

# Build and run ex01
cd ../ex01
make
./iter

# Build and run ex02
cd ../ex02
make
./array
```

### Makefile Rules
- `make`: Compiles the binary.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the compiled executable.
- `make re`: Performs a clean rebuild.

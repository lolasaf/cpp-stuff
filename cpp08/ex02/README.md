# Exercise 02: MutantStack

## Request

Create a `MutantStack` class that:
- Is implemented in terms of `std::stack` (inheritance or composition)
- Offers **all** member functions of `std::stack`
- **Additionally** provides iterators (begin, end, etc.)
- Should work exactly like `std::stack` but be iterable

**Test requirement:** If you replace `MutantStack` with `std::list` in the test code, the output should be the same.

## Theory Needed

### 1. Container Adapters (NEW CONCEPT)
`std::stack` is a **container adapter**, not a container itself. It:
- Uses an underlying container (by default `std::deque`)
- Provides a restricted interface (LIFO: Last In, First Out)
- Does NOT provide iterators (that's why we need to fix this!)

**std::stack member functions:**
- `push(value)` - add element to top
- `pop()` - remove top element
- `top()` - access top element
- `empty()` - check if empty
- `size()` - get number of elements

### 2. Inheritance vs Composition
You have two options:

**Option A: Inheritance (Recommended)**
```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Add iterator functionality
};
```

**Option B: Composition**
```cpp
template <typename T>
class MutantStack {
private:
    std::stack<T> stack;
public:
    // Delegate all std::stack methods
    // Add iterator functionality
};
```

**Recommendation:** Use inheritance - it's simpler and you get all `std::stack` methods automatically.

### 3. Accessing Underlying Container (NEW CONCEPT)
`std::stack` has a **protected** member `c` that is the underlying container!

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // The underlying container is accessible as this->c
    // It's of type std::stack<T>::container_type (usually std::deque<T>)
};
```

**Key insight:** Since `std::stack` uses `std::deque` by default, and `std::deque` has iterators, you can expose those iterators!

### 4. Typedefs for Iterators (NEW CONCEPT)
You need to provide iterator types that match the underlying container:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
typedef typename std::stack<T>::container_type::const_iterator const_iterator;
typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
```

**Key points:**
- `typename` is required because `container_type` is a dependent type
- `std::stack<T>::container_type` is the type of the underlying container
- You're just exposing the iterators that already exist in the underlying container

### 5. Iterator Methods
Provide these methods:

```cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
const_iterator begin() const { return this->c.begin(); }
const_iterator end() const { return this->c.end(); }
// Same for reverse iterators: rbegin(), rend()
```

### 6. Template Classes
This is a **class template**, not just a function template:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
    // ...
};
```

**Usage:**
```cpp
MutantStack<int> mstack;
MutantStack<std::string> stringStack;
```

## New Theoretical Concepts Introduced

1. **Container Adapters** - Understanding that `std::stack` wraps another container
2. **Protected Members** - Accessing protected members through inheritance
3. **Dependent Types** - Using `typename` keyword for template-dependent types
4. **Iterator Exposure** - Exposing iterators from underlying container
5. **Class Templates** - Templates for entire classes, not just functions

## Implementation Hints

1. **Inherit from std::stack:**
   ```cpp
   template <typename T>
   class MutantStack : public std::stack<T> {
   ```

2. **Add iterator typedefs:**
   - Use `typename std::stack<T>::container_type::iterator`
   - Don't forget `typename` keyword!

3. **Implement begin() and end():**
   - Return `this->c.begin()` and `this->c.end()`
   - Provide both const and non-const versions

4. **Optional: Add reverse iterators:**
   - `rbegin()` and `rend()`
   - Useful for iterating in reverse

5. **All std::stack methods are inherited:**
   - You don't need to reimplement `push()`, `pop()`, `top()`, etc.
   - They work automatically through inheritance

6. **Test compatibility:**
   - Your MutantStack should work exactly like std::stack
   - Plus it should be iterable like std::list

## Testing Checklist

- [ ] Test all std::stack functionality (push, pop, top, size, empty)
- [ ] Test forward iteration (begin to end)
- [ ] Test reverse iteration (rbegin to rend)
- [ ] Test const iterators
- [ ] Compare output with std::list version (should match)
- [ ] Test with different types (int, string, etc.)
- [ ] Test copy constructor and assignment
- [ ] Test with empty stack
- [ ] Test with single element
- [ ] Test with many elements

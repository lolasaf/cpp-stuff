# Exercise 00: Easy find

## Request

Write a function template `easyfind` that:
- Accepts a type `T` (template parameter)
- Takes two parameters:
  1. First parameter: an object of type `T` (a container of integers)
  2. Second parameter: an integer to search for
- Finds the **first occurrence** of the integer in the container
- If not found: throw an exception or return an error value (study how standard containers behave)

**Note:** You don't have to handle associative containers (like `std::map`, `std::set`).

## Theory Needed

### 1. Function Templates (NEW CONCEPT)
Function templates allow you to write generic functions that work with different types.

**Syntax:**
```cpp
template <typename T>
void functionName(T param) {
    // implementation
}
```

**Key points:**
- `template <typename T>` declares a template parameter `T`
- `T` can be any type (int, std::vector<int>, std::list<int>, etc.)
- The compiler generates specific versions of the function for each type used
- Templates are typically defined in header files (not .cpp files)

### 2. STL Containers and Iterators
Since this is Module 08, you can now use STL containers!

**Sequential Containers:**
- `std::vector<int>` - dynamic array
- `std::list<int>` - doubly-linked list
- `std::deque<int>` - double-ended queue

**Iterators:**
- Iterators are objects that point to elements in containers
- `begin()` returns iterator to first element
- `end()` returns iterator to one past the last element
- Use `*it` to dereference and get the value
- Use `++it` to move to next element

**Example:**
```cpp
std::vector<int> vec;
// ... add elements ...
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    if (*it == target) {
        // found!
    }
}
```

### 3. STL Algorithms (NEW CONCEPT)
The `<algorithm>` header provides useful functions like `std::find()`.

**std::find():**
```cpp
#include <algorithm>

std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), value);
if (it != vec.end()) {
    // found at position it
} else {
    // not found
}
```

**However:** The exercise asks you to implement your own `easyfind`, so you can either:
- Use `std::find()` internally, OR
- Implement your own search logic using iterators

### 4. Exceptions
When the value is not found, you should throw an exception.

**Creating custom exceptions:**
```cpp
class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found";
    }
};
```

**Throwing:**
```cpp
throw NotFoundException();
```

## New Theoretical Concepts Introduced

1. **Function Templates** - Generic programming, write once, use with multiple types
2. **STL Containers** - Standard library containers (vector, list, deque)
3. **STL Iterators** - Iterator pattern for traversing containers
4. **STL Algorithms** - Standard algorithms like `std::find()` (optional to use)

## Implementation Hints

1. Your function template should work with any container that has iterators
2. Use `typename T::iterator` to get the iterator type for container `T`
3. Compare `*it` with the target value
4. Return the iterator if found, throw exception if not found
5. Test with different containers: `std::vector<int>`, `std::list<int>`, `std::deque<int>`

## Testing Checklist

- [ ] Test with `std::vector<int>`
- [ ] Test with `std::list<int>`
- [ ] Test with `std::deque<int>`
- [ ] Test when value exists (first occurrence)
- [ ] Test when value doesn't exist (exception)
- [ ] Test with empty container
- [ ] Test with duplicate values (should find first)

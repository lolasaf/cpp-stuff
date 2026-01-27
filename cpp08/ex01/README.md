# Exercise 01: Span

## Request

Develop a `Span` class that:
- Stores a maximum of `N` integers (N is `unsigned int`, passed to constructor)
- Has `addNumber(int)` member function to add a single number
- Throws an exception if trying to add more than N elements
- Has `shortestSpan()` member function: finds the shortest distance between any two numbers
- Has `longestSpan()` member function: finds the longest distance between any two numbers
- Throws an exception if there are 0 or 1 numbers stored (can't calculate span)
- Must be testable with at least 10,000 numbers
- **Bonus:** Implement a function to add multiple numbers using a range of iterators

**Example:**
```cpp
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;  // Output: 2
std::cout << sp.longestSpan() << std::endl;   // Output: 14
```

## Theory Needed

### 1. STL Containers for Storage
You need to store integers. Good choices:
- `std::vector<int>` - efficient, random access
- `std::list<int>` - if you don't need random access
- `std::deque<int>` - double-ended queue

**Recommendation:** Use `std::vector<int>` for efficient storage and sorting.

### 2. STL Algorithms (NEW CONCEPT - Heavy Use)
This exercise heavily uses `<algorithm>` header functions:

**std::sort():**
```cpp
#include <algorithm>
std::vector<int> vec = {3, 1, 4, 1, 5};
std::sort(vec.begin(), vec.end());  // {1, 1, 3, 4, 5}
```

**std::min_element() / std::max_element():**
```cpp
std::vector<int>::iterator minIt = std::min_element(vec.begin(), vec.end());
std::vector<int>::iterator maxIt = std::max_element(vec.begin(), vec.end());
int minVal = *minIt;
int maxVal = *maxIt;
```

**std::adjacent_difference():**
```cpp
#include <numeric>  // Also useful!
// Calculates differences between adjacent elements
```

**For shortestSpan():**
- Sort the container
- Find minimum difference between adjacent elements
- Hint: Use `std::adjacent_difference()` or iterate and compare adjacent elements

**For longestSpan():**
- Find minimum and maximum values
- Return `max - min`
- Hint: Use `std::min_element()` and `std::max_element()`, or sort and use first/last

### 3. Iterator Ranges (NEW CONCEPT)
To add multiple numbers at once, you need to accept iterator ranges:

**Template member function:**
```cpp
template <typename Iterator>
void addRange(Iterator begin, Iterator end) {
    // Add all elements from begin to end (exclusive)
    // Check that you don't exceed N elements
}
```

**Usage:**
```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
span.addRange(numbers.begin(), numbers.end());
```

**Key points:**
- `begin` points to first element
- `end` points to one past the last element
- Use `++begin` to iterate: `while (begin != end) { ... ++begin; }`
- Works with any container that has iterators

### 4. Exception Handling
Create custom exceptions:
```cpp
class SpanFullException : public std::exception {
    // Thrown when trying to add more than N elements
};

class NoSpanException : public std::exception {
    // Thrown when trying to calculate span with < 2 elements
};
```

### 5. Orthodox Canonical Form
Remember: Your class must follow Orthodox Canonical Form:
- Default constructor (if needed)
- Copy constructor
- Copy assignment operator
- Destructor

## New Theoretical Concepts Introduced

1. **STL Algorithms** - `<algorithm>` header functions (`std::sort`, `std::min_element`, `std::max_element`, `std::adjacent_difference`)
2. **Iterator Ranges** - Generic functions that accept `[begin, end)` iterator pairs
3. **Template Member Functions** - Member functions that are templates
4. **Efficient Algorithms** - Using STL algorithms instead of manual loops

## Implementation Hints

1. **Storage:** Use `std::vector<int>` to store numbers
2. **addNumber():** Check `size() < N` before adding, throw if full
3. **shortestSpan():**
   - Check if size < 2, throw exception
   - Sort the vector
   - Find minimum difference between adjacent elements
   - Hint: Iterate through sorted vector, calculate `vec[i+1] - vec[i]`, find minimum
4. **longestSpan():**
   - Check if size < 2, throw exception
   - Find min and max (or sort and use first/last)
   - Return `max - min`
5. **addRange() (bonus):**
   - Template function: `template <typename Iterator>`
   - Calculate how many elements will be added: `std::distance(begin, end)`
   - Check if adding them would exceed N
   - Use iterator to add: `while (begin != end) { addNumber(*begin); ++begin; }`

## Testing Checklist

- [ ] Basic functionality: add 5 numbers, calculate spans
- [ ] Test with exactly N numbers
- [ ] Test exception when adding more than N numbers
- [ ] Test exception when calculating span with 0 numbers
- [ ] Test exception when calculating span with 1 number
- [ ] Test with 10,000+ numbers (performance test)
- [ ] Test shortestSpan with various number sets
- [ ] Test longestSpan with various number sets
- [ ] Test addRange() with different containers (vector, list, array)
- [ ] Test edge cases: all same numbers, negative numbers, large numbers

#ifndef SPAN_HPP
# define SPAN_HPP

// TODO: Include necessary headers
// #include <vector>
// #include <algorithm>
// #include <exception>
// #include <stdexcept>

class Span
{
private:
    // TODO: Add private members
    // - Maximum size (unsigned int N)
    // - Container to store integers (std::vector<int> recommended)
    
    // TODO: Make sure to follow Orthodox Canonical Form
    // You might need to make some constructors private or delete them
    
public:
    // TODO: Orthodox Canonical Form
    // - Constructor that takes unsigned int N
    // - Copy constructor
    // - Copy assignment operator
    // - Destructor
    
    // TODO: Member functions
    // void addNumber(int number);
    //   - Adds a single number to the Span
    //   - Throws exception if already at capacity
    
    // unsigned int shortestSpan() const;
    //   - Returns the shortest distance between any two numbers
    //   - Throws exception if less than 2 numbers stored
    //   - Hint: Sort the container, find minimum difference between adjacent elements
    
    // unsigned int longestSpan() const;
    //   - Returns the longest distance between any two numbers
    //   - Throws exception if less than 2 numbers stored
    //   - Hint: Find min and max, return max - min
    
    // TODO: Bonus - Iterator range function
    // template <typename Iterator>
    // void addRange(Iterator begin, Iterator end);
    //   - Adds multiple numbers using iterator range
    //   - Check that adding won't exceed capacity
    //   - Hint: Use std::distance() to calculate how many elements
};

// TODO: Custom exception classes
// class SpanFullException : public std::exception { ... };
// class NoSpanException : public std::exception { ... };

#endif

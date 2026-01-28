/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:41:46 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/27 21:58:30 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>
#include <iterator>

class Span {
private:
    unsigned int N;
	std::vector<int> numbers;

public:
	Span(unsigned int maxSize);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
    
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
};


class SpanFullException : public std::exception {
public:
	const char* what() const throw() {
		return "Span is full";
	}
};

class NoSpanException : public std::exception {
public:
	const char* what() const throw() {
		return "Not enough numbers to find a span";
	}
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	unsigned int distance = static_cast<unsigned int>(std::distance(begin, end));
	
	if (numbers.size() + distance > N) {
		throw SpanFullException();
	}
	
	numbers.insert(numbers.end(), begin, end);
}

#endif

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

#endif

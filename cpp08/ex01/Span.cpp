/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:41:39 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/27 21:57:59 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int maxSize) : N(maxSize) {
	numbers.reserve(maxSize);
}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= N) {
		throw ::SpanFullException();
	}
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw ::NoSpanException();
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = static_cast<unsigned int>(sortedNumbers[i] - sortedNumbers[i - 1]);
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw ::NoSpanException();
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return static_cast<unsigned int>(sortedNumbers.back() - sortedNumbers.front());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:41:54 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/28 21:03:59 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Test 0: Subject Test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
	std::cout << std::endl << "=== Test 1: Span Full Exception ===" << std::endl;
	try {
		sp.addNumber(20);
	} catch (const SpanFullException& e) {
		std::cout << e.what() << std::endl;
	}
    
    std::cout << std::endl << "=== Test 2: No Span Exception (0 numbers) ===" << std::endl;
	Span emptySpan = Span(5);
	try {
		emptySpan.shortestSpan();
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}
	
    std::cout << std::endl << "=== Test 3: No Span Exception (1 number) ===" << std::endl;
	Span oneSpan = Span(5);
	oneSpan.addNumber(42);
	try {
		oneSpan.shortestSpan();
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 4: All Same Numbers ===" << std::endl;
	Span sameNumbersSpan = Span(5);
	for (int i = 0; i < 5; ++i) {
		sameNumbersSpan.addNumber(10);
	}
	try {
		std::cout << "Shortest span: " << sameNumbersSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sameNumbersSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 5: Already Sorted Numbers ===" << std::endl;
	Span sortedSpan = Span(5);
	for (int i = 1; i <= 5; ++i) {
		sortedSpan.addNumber(i * 10);
	}
	try {
		std::cout << "Shortest span: " << sortedSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sortedSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== Test 6: Negative Numbers ===" << std::endl;
	Span negativeSpan = Span(5);
	negativeSpan.addNumber(-10);
	negativeSpan.addNumber(-20);
	negativeSpan.addNumber(-5);
	negativeSpan.addNumber(-15);
	negativeSpan.addNumber(-30);
	try {
		std::cout << "Shortest span: " << negativeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << negativeSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 7: Large Number of Random Numbers ===" << std::endl;
	Span largeSpan = Span(10000);
	std::srand((std::time(0)));
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(rand());
    }
    try {
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const NoSpanException& e) {
        std::cout << e.what() << std::endl;
    } catch (const SpanFullException& e) {
        std::cout << e.what() << std::endl;
    }
    
	std::cout << std::endl << "=== Test 8: INT_MIN and INT_MAX ===" << std::endl;
	Span intMinMaxSpan = Span(2);
	intMinMaxSpan.addNumber(INT_MIN);
	intMinMaxSpan.addNumber(INT_MAX);
	try {
		std::cout << "Shortest span: " << intMinMaxSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << intMinMaxSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:41:54 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/29 00:25:10 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <climits>

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
	
	std::cout << std::endl << "=== Test 9: addRange() with iterators ===" << std::endl;
	Span rangeSpan = Span(10);
	
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	rangeSpan.addRange(vec.begin(), vec.end());
	std::cout << "Added 3 numbers from vector" << std::endl;
	
	std::list<int> lst;
	lst.push_back(400);
	lst.push_back(500);
	rangeSpan.addRange(lst.begin(), lst.end());
	std::cout << "Added 2 numbers from list" << std::endl;
	
	int arr[] = {600, 700, 800, 900, 1000};
	rangeSpan.addRange(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::cout << "Added 5 numbers from array" << std::endl;
	
	try {
		std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== Test 10: addRange() exceptions ===" << std::endl;
	Span smallSpan = Span(3);
	std::vector<int> largeVec;
	for (int i = 0; i < 5; ++i) {
		largeVec.push_back(i);
	}
	try {
		smallSpan.addRange(largeVec.begin(), largeVec.end());
		std::cout << "Should not reach here!!" << std::endl;
	} catch (const SpanFullException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== Test 11: addRange() with Large Dataset ===" << std::endl;
	Span largeRangeSpan = Span(5000);
	std::vector<int> largeDataset;
	for (int i = 0; i < 5000; ++i) {
		largeDataset.push_back(i * 2);
	}
	largeRangeSpan.addRange(largeDataset.begin(), largeDataset.end());
	std::cout << "Added 5000 numbers using addRange() in a single call" << std::endl;
	try {
		std::cout << "Shortest span: " << largeRangeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << largeRangeSpan.longestSpan() << std::endl;
	} catch (const NoSpanException& e) {
		std::cout << e.what() << std::endl;
	}
	
    return 0;
}

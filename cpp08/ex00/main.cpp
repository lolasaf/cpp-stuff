/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:11:19 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/27 21:32:46 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iterator>

int main()
{   
	std::cout << std::endl <<"=== Test 1: Vector ===" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i <= 5; ++i) {
		vec.push_back(i * 10);
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
		std::vector<int>::iterator it2 = easyfind(vec, 100); // this should throw
		std::cout << "Found: " << *it2 << std::endl;
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "\n=== Test 2: List ===" << std::endl;
	std::list<int> lst;
	for (int i = 1; i <= 5; ++i) {
		lst.push_back(i * 15);
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 45);
		std::cout << "Found: " << *it << std::endl;
		std::list<int>::iterator it2 = easyfind(lst, 100); // this should throw
		std::cout << "Found: " << *it2 << std::endl;
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "=== Test 3: Deque ===" << std::endl;
	std::deque<int> deq;
	for (int i = 1; i <= 5; ++i) {
		deq.push_back(i * 20);
	}
	try {
		std::deque<int>::iterator it = easyfind(deq, 60);
		std::cout << "Found: " << *it << std::endl;
		std::deque<int>::iterator it2 = easyfind(deq, 110); // this should throw
		std::cout << "Found: " << *it2 << std::endl;
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "=== Test 4: Empty Container ===" << std::endl;
	std::vector<int> emptyVec;
	try {
		std::vector<int>::iterator it = easyfind(emptyVec, 0); // this should throw
		std::cout << "Found: " << *it << std::endl;
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "=== Test 5: Duplicate Values ===" << std::endl;
	std::vector<int> dupVec;
	dupVec.push_back(10);
	dupVec.push_back(15);
	dupVec.push_back(20);
	dupVec.push_back(10);
	dupVec.push_back(30);
	dupVec.push_back(20);
	try {
		std::vector<int>::iterator it = easyfind(dupVec, 10);
		std::cout << "Found: " << *it << " at index: " << std::distance(dupVec.begin(), it) << std::endl; // should print first 10
		it = easyfind(dupVec, 20);
		std::cout << "Found: " << *it << " at index: " << std::distance(dupVec.begin(), it) << std::endl; // should print first 20
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
    
	std::cout << std::endl << std::endl;
	std::cout << "=== Test 6: Const Container ===" << std::endl;
	int arr[] = {5, 10, 15, 20, 25};
	const std::vector<int> constVec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try {
		std::vector<int>::const_iterator it = easyfind(constVec, 15);
		std::cout << "Found: " << *it << std::endl;
	} catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}

    return 0;
}

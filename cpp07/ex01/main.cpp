/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:44 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/26 00:26:59 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Test functions
void printInt(const int& n) {
    std::cout << n << " ";
}

void incrementInt(int& n) {
    n += 10;
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

// Template function
template <typename T>
void printTemplate(const T& value) {
    std::cout << value << " ";
}

int main() {
    // Test 1: Non-const array with const function
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Test 1: Non-const array: ";
    ::iter(intArray, 5, &printInt);
    std::cout << std::endl << std::endl;
    
    // Test 2: Non-const array with non-const function (modification)
    std::cout << "Test 2: Before increment: ";
    ::iter(intArray, 5, &printInt);
    std::cout << std::endl;
    ::iter(intArray, 5, &incrementInt);
    std::cout << "Test 2: After increment: ";
    ::iter(intArray, 5, &printInt);
    std::cout << std::endl << std::endl;
    
    // Test 3: Const array with const function
    const int constArray[] = {10, 20, 30, 40, 50};
    std::cout << "Test 3: Const array: ";
    ::iter(constArray, 5, &printInt);
    std::cout << std::endl << std::endl;
    
    // Test 4: String array (any type of array)
    std::string strArray[] = {"hello", "world", "cpp"};
    std::cout << "Test 4: String array: ";
    ::iter(strArray, 3, &printString);
    std::cout << std::endl << std::endl;
    
    // Test 5: Template function
    float floatArray[] = {1.5f, 2.5f, 3.5f};
    std::cout << "Test 5: Template function with float: ";
    ::iter(floatArray, 3, &printTemplate<float>);
    std::cout << std::endl;
    
    return 0;
}
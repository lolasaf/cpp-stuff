/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:30:15 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/25 19:44:42 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(NULL));
    // Test multiple times to see different random types
	for (int i = 0; i < 5; i++) {
		std::cout << "Test " << (i + 1) << ":" << std::endl;
		
		// Generate a random Base pointer
		Base* ptr = generate();
		
		// Identify using pointer
		std::cout << "  identify(Base*): ";
		identify(ptr);
		
		// Identify using reference
		std::cout << "  identify(Base&): ";
		identify(*ptr);
		
		// Clean up
		delete ptr;
		std::cout << std::endl;
	}

    return 0;
}
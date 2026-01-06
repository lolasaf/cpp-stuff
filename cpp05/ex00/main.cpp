/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:44:43 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/06 22:54:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1;
		std::cout << b1 << std::endl;
		b1.decrementGrade(); // throws exception
		std::cout << b1 << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Bureaucrat GradeTooLow Exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // throws an exception
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade(); // This should throw an exception
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	// Test invalid constructor (grade too high)
	try {
		Bureaucrat invalid("Test", 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test invalid constructor (grade too low)
	try {
		Bureaucrat invalid("Test", 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test copy constructor
	Bureaucrat original("Original", 50);
	Bureaucrat copy(original);
	std::cout << copy << std::endl;

	// Test copy assignment
	Bureaucrat assigned;
	assigned = original;
	std::cout << assigned << std::endl;

	return 0;
}
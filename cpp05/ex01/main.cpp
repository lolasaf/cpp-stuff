/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:44:43 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/07 22:47:28 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== BUREAUCRAT TESTS ===" << std::endl;

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

	std::cout << std::endl << "=== FORM TESTS ===" << std::endl;

	// Test Form creation and operator<<
	try {
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test Form with grade too high (< 1)
	try {
		Form invalid("Invalid Form", 0, 50);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test Form with grade too low (> 150)
	try {
		Form invalid("Invalid Form", 50, 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Eception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== SIGNING TESTS ===" << std::endl;

	// Test successful signing
	try {
		Bureaucrat boss("Boss", 1);
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test failed signing (grade too low)
	try {
		Bureaucrat intern("Intern", 100);
		Form topSecret("Top Secret", 10, 5);
		std::cout << topSecret << std::endl;
		intern.signForm(topSecret);  // Should fail
		std::cout << topSecret << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test signing at exact grade requirement
	try {
		Bureaucrat mid("Mid-Level", 50);
		Form exactForm("Exact Form", 50, 50);
		std::cout << exactForm << std::endl;
		mid.signForm(exactForm);  // Should succeed (grade 50 == requirement 50)
		std::cout << exactForm << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:44:43 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 22:27:54 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

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

	std::cout << std::endl << std::endl << "=== SHRUBBERY CREATION FORM TESTS ===" << std::endl << std::endl;

	// Test ShrubberyCreationForm - successful execution
	try {
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		
		// Try to execute unsigned form - should fail
		std::cout << "Attempting to execute unsigned form..." << std::endl;
		gardener.executeForm(shrub);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("garden");
		
		// Sign the form
		gardener.signForm(shrub);
		std::cout << shrub << std::endl;
		
		// Execute the form - should create garden_shrubbery file
		gardener.executeForm(shrub);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test ShrubberyCreationForm - grade too low to execute
	try {
		Bureaucrat lowRank("LowRank", 140);
		ShrubberyCreationForm shrub("office");
		
		lowRank.signForm(shrub);  // Can sign (needs 145)
		lowRank.executeForm(shrub);  // Cannot execute (needs 137)
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== ROBOTOMY REQUEST FORM TESTS ===" << std::endl << std::endl;

	// Test RobotomyRequestForm - multiple executions to see 50% success rate
	try {
		Bureaucrat engineer("Engineer", 40);
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		
		engineer.signForm(robot);
		std::cout << robot << std::endl;
		
		// Execute multiple times to see random results
		std::cout << "\nExecuting robotomy 5 times:" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << "Attempt " << (i + 1) << ": ";
			engineer.executeForm(robot);
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test RobotomyRequestForm - grade too low
	try {
		Bureaucrat intern("Intern", 100);
		RobotomyRequestForm robot("C3PO");
		
		intern.signForm(robot);  // Cannot sign (needs 72)
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== PRESIDENTIAL PARDON FORM TESTS ===" << std::endl << std::endl;

	// Test PresidentialPardonForm - successful
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		std::cout << pardon << std::endl;
		
		president.executeForm(pardon);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test PresidentialPardonForm - grade too low to sign
	try {
		Bureaucrat manager("Manager", 30);
		PresidentialPardonForm pardon("Arthur Dent");
		
		manager.signForm(pardon);  // Cannot sign (needs 25)
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test PresidentialPardonForm - can sign but not execute
	try {
		Bureaucrat senator("Senator", 10);
		PresidentialPardonForm pardon("Zaphod");
		
		senator.signForm(pardon);  // Can sign (needs 25)
		senator.executeForm(pardon);  // Cannot execute (needs 5)
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== POLYMORPHISM TESTS ===" << std::endl << std::endl;

	// Test polymorphism with AForm pointers
	try {
		Bureaucrat boss("Boss", 1);
		
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("park");
		forms[1] = new RobotomyRequestForm("Wall-E");
		forms[2] = new PresidentialPardonForm("Marvin");
		
		for (int i = 0; i < 3; i++) {
			std::cout << *forms[i] << std::endl;
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
			std::cout << std::endl;
		}
		
		// Clean up
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== COPY TESTS ===" << std::endl << std::endl;

	// Test copy constructor for derived forms
	try {
		ShrubberyCreationForm original("original");
		ShrubberyCreationForm copied(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copied: " << copied << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== INTERN TESTS ===" << std::endl << std::endl;

	// Test Intern creating valid forms
	try {
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);
		AForm* form;

		// Create shrubbery creation form
		form = someRandomIntern.makeForm("shrubbery creation", "backyard");
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;

		std::cout << std::endl;

		// Create robotomy request form
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;

		std::cout << std::endl;

		// Create presidential pardon form
		form = someRandomIntern.makeForm("presidential pardon", "Marvin");
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test Intern with unknown form type
	std::cout << std::endl << "Testing unknown form type:" << std::endl;
	try {
		Intern intern;
		AForm* form = intern.makeForm("coffee request", "everyone");
		delete form;  // Won't reach here
	}
	catch (const Intern::UnknownFormException& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
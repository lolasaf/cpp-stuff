/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:31:52 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 22:25:40 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


const std::string	Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::FormCreator	Intern::_formCreators[3] = {
	&Intern::createShrubberyCreationForm,
	&Intern::createRobotomyRequestForm,
	&Intern::createPresidentialPardonForm
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::createShrubberyCreationForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequestForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardonForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const {
	for (int i = 0; i < 3; i++) {
		if (formName == _formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*_formCreators[i])(target);
		}
	}
	throw UnknownFormException();
}
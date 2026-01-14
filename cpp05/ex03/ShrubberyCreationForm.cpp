/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:51:05 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 20:14:32 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void	ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile)
	{
		// failed to create file
		throw FileCreationException();
	}
	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:30:17 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/07 23:21:48 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:	_name("Default"),
		_isSigned(false),
		_signGrade(150),
		_executeGrade(150)
{}

AForm::AForm(const AForm& other)
	:	_name(other._name),
		_isSigned(other._isSigned),
		_signGrade(other._signGrade),
		_executeGrade(other._executeGrade)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

AForm::AForm(std::string const& name, int signGrade, int executeGrade)
	:	_name(name),
		_isSigned(false),
		_signGrade(signGrade),
		_executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

std::string const&	AForm::getName() const
{
	return this->_name;
}

bool	AForm::isSigned() const
{
	return this->_isSigned;
}

int	AForm::getSignGrade() const
{
	return this->_signGrade;
}

int	AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form " << f.getName()
	   << ", Sign grade: " << f.getSignGrade()
	   << ", Execute grade: " << f.getExecuteGrade()
	   << ", Signed: " << (f.isSigned() ? "Yes" : "No") << ".";
	return os;
}
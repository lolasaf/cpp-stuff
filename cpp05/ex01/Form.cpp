/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:30:17 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/07 22:38:59 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:	_name("Default"),
		_isSigned(false),
		_signGrade(150),
		_executeGrade(150)
{}

Form::Form(const Form& other)
	:	_name(other._name),
		_isSigned(other._isSigned),
		_signGrade(other._signGrade),
		_executeGrade(other._executeGrade)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

Form::Form(std::string const& name, int signGrade, int executeGrade)
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

std::string const&	Form::getName() const
{
	return this->_name;
}

bool	Form::isSigned() const
{
	return this->_isSigned;
}

int	Form::getSignGrade() const
{
	return this->_signGrade;
}

int	Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName()
	   << ", Sign grade: " << f.getSignGrade()
	   << ", Execute grade: " << f.getExecuteGrade()
	   << ", Signed: " << (f.isSigned() ? "Yes" : "No") << ".";
	return os;
}
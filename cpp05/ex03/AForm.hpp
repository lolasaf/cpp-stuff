/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:30:01 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 21:28:37 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>


class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm(); // virtual destructor for abstract class
	
	AForm(std::string const& name, int signGrade, int executeGrade);

	std::string const&	getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void				beSigned(const Bureaucrat& b);
	
	void	execute(Bureaucrat const& executor) const; // TODO: implement execute method
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form Grade is too high!";
		}	
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form Grade is too low!";
		}
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form is not signed!";
		}
	};
	
protected:
	virtual void	executeAction() const = 0; // Derived classes must implement this

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_executeGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
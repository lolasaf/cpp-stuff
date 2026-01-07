/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:30:01 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/07 22:46:55 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>


class Bureaucrat;

class Form {
public:
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	
	Form(std::string const& name, int signGrade, int executeGrade);

	std::string const&	getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void				beSigned(const Bureaucrat& b);
	
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

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_executeGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
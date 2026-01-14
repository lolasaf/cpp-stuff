/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:55:45 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 19:58:54 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(const std::string& name, int grade);

	const std::string&	getName() const;
	int					getGrade() const;
	
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(AForm& f);

	void	executeForm(AForm const& form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high!";
		}
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low!";
		}
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
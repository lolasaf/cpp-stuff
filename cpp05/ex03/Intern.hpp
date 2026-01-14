/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:31:43 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/14 22:18:34 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);	
	~Intern();
	
	AForm*	makeForm(const std::string& formName, const std::string& target) const;
	
	class UnknownFormException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Intern Error: Unknown form type requested!";
		}
	};

private:
	static const std::string	_formNames[3];
	typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
	static FormCreator	_formCreators[3];

	AForm*	createShrubberyCreationForm(const std::string& target) const;
	AForm*	createRobotomyRequestForm(const std::string& target) const;
	AForm*	createPresidentialPardonForm(const std::string& target) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:48:09 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 17:11:52 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

public:
	Animal(); //constructor
	Animal(const Animal& other); // copy constructor
	Animal& operator=(const Animal& other); // assignment operator overload
	virtual ~Animal(); // destructor

	std::string	getType() const;
	void		setType(const std::string& intype);
	
	virtual void		makeSound() const;
	
protected:
	std::string type;

};

#endif
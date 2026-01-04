/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:48:09 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 17:42:02 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

public:
	WrongAnimal(); //constructor
	WrongAnimal(const WrongAnimal& other); // copy constructor
	WrongAnimal& operator=(const WrongAnimal& other); // assignment operator overload
	virtual ~WrongAnimal(); // destructor

	std::string	getType() const;
	void		setType(const std::string& intype);
	
	void makeSound() const; // <----- WRONG! missing virtual
	
protected:
	std::string type;

};

#endif
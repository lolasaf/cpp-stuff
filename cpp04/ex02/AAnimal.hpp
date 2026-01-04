/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:48:09 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:40:49 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal {

public:
	AAnimal(); //constructor
	AAnimal(const AAnimal& other); // copy constructor
	AAnimal& operator=(const AAnimal& other); // assignment operator overload
	virtual ~AAnimal(); // destructor

	std::string	getType() const;
	void		setType(const std::string& intype);
	
	virtual void		makeSound() const = 0;
	
protected:
	std::string type;

};

#endif
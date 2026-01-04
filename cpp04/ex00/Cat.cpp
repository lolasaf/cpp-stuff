/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:45:53 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:14:08 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& other) {
	*this = other;
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "😻 Meow 😻 Meow 😻 Meow 😻" << std::endl;
}
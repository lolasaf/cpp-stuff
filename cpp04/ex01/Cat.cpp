/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:45:53 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:28:58 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), _brain(NULL) {
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->_brain = NULL;
	*this = other;
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "😻 Meow 😻 Meow 😻 Meow 😻" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}

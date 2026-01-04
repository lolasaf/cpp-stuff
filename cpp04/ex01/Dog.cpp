/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:05:22 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:28:37 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), _brain(NULL) {
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->_brain = NULL;
	*this = other;
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Copy assignment operator called for Dog" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "🐶 3aww 🐶 3aww 🐶 3aww 🐶" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}

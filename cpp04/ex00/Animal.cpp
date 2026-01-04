/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:49:55 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 19:55:01 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("any") {
	std::cout << "Default consructor called for Animal" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Assignment operator called for Animal" << std::endl;
	if (this != &other)
		this->type = other.getType();
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Making a general animal sound! 🫎 🦑🪿 🐒" << std::endl;
}
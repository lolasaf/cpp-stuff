/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:49:55 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:12:57 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("any") {
	std::cout << "Default consructor called for Animal" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << "Copy constructor called for Animal" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "Assignment operator called for Animal" << std::endl;
	if (this != &other)
		this->type = other.getType();
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Animal Destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::makeSound() const {
	std::cout << "Making a general animal sound! 🫎 🦑🪿 🐒" << std::endl;
}

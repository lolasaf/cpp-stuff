/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:45:53 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 17:21:07 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "Default consructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	*this = other;
	std::cout << "Copy construcor called for WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Copy assignment operator called for WrongCat" << std::endl;
	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "😻 Meow 😻 Meow 😻 Meow 😻" << std::endl;
}
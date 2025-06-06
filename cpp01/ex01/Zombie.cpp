/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:25:46 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 00:49:01 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	// Zombie is created
}

Zombie::Zombie(std::string name) : _name(name) {
	// Zombie is created with name
}

Zombie::~Zombie() {
	std::cout << "Zombie destructed with name: " << this->_name << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce( void ) {
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

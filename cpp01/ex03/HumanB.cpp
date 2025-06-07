/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:51:58 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 18:57:03 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) 
	: _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() const{
	
	if (this->_weapon) // only attack if armed
		std::cout	<< this->_name
					<< " attacks with their "
					<< (*this->_weapon).getType()
					<< std::endl;
	else
		std::cout	<< this->_name
					<< " has no weapon ≧☉_☉≦"
					<< std::endl;
}

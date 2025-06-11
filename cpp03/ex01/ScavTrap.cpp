/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:34:24 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/10 23:52:19 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->_guard = false;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->_guard = false;
    std::cout << "ScavTrap named constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->getHitPoints() < 1 || this->getEnergyPoints() < 1)
	{
		std::cout	<< "ScavTrap " << this->getName() << " cannot attack! (⊙﹏⊙)"
					<< std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " << this->getName() << " attacked " << target
				<< " causing " << this->getAttackDamage() << " points of damage (^▼^)ψ !"
				<< std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
	this->_guard = true;
	std::cout	<<  "ScavTrap " << this->getName()
				<< " is now in Gate keeper mode. ⤜(ⱺ ʖ̯ⱺ)⤏ "
				<< std::endl;
}
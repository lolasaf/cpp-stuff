/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:39:47 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/10 22:03:07 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
	_name(""),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "ClapTrap named constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}


std::string ClapTrap::getName() const {
	return this->_name;
}

int ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

ClapTrap& ClapTrap::setName(const std::string& name) {
	std::cout	<< "ClapTrap setName called. Name: |" << this->_name 
				<< "| -> |" << name << "|" << std::endl;
	this->_name = name;
	return *this;
}

ClapTrap& ClapTrap::setHitPoints(unsigned int hitPoints) {
	std::cout	<< "ClapTrap setHitPoints called. HitPoints: " << this->_hitPoints 
				<< " -> " << hitPoints << std::endl;
	this->_hitPoints = hitPoints;
	return *this;
}

ClapTrap& ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	std::cout	<< "ClapTrap setEnergyPoints called. EnergyPoints: " << this->_energyPoints 
				<< " -> " << energyPoints << std::endl;
	this->_energyPoints = energyPoints;
	return *this;
}

ClapTrap& ClapTrap::setAttackDamage(unsigned int attackDamage) {
	std::cout	<< "ClapTrap setAttackDamage called. AttackDamage: " << this->_attackDamage 
				<< " -> " << attackDamage << std::endl;
	this->_attackDamage = attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints < 1 || this->_energyPoints < 1)
	{
		std::cout	<< "ClapTrap " << this->_name << " cannot attack! (⊙﹏⊙)"
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name << " attacked " << target
				<< " causing " << this->_attackDamage << " points of damage (^▼^)ψ ! "
				<< " [EP: " << this->_energyPoints << " -> "; 
	this->_energyPoints--;
	std::cout	<< this->_energyPoints << "]"
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout	<< "ClapTrap " << this->_name << " takes " << amount << " damage (⊙︿⊙)."
				<< " [HP: " << this->_hitPoints << " -> ";
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout	<< this->_hitPoints << "]"
				<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
	{
		std::cout	<< "ClapTrap has zero EP or HP to repair itself! (∥￣■￣∥)"
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name << " is repaired with "
				<< amount << " points (✿◠‿◠). "
				<< "[HP: " << this->_hitPoints << " -> ";
	this->_hitPoints += amount;
	std::cout	<< this->_hitPoints << "]"
				<< " [EP: " << this->_energyPoints << " -> "; 
	this->_energyPoints--;
	std::cout	<< this->_energyPoints << "]"
				<< std::endl;
}

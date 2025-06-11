/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:59:43 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/10 21:01:05 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
# define CLAPTRAP

#include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	ClapTrap(std::string name);

	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

	ClapTrap& setName(const std::string& name);
	ClapTrap& setHitPoints(unsigned int hitPoints);
	ClapTrap& setEnergyPoints(unsigned int energyPoints);
	ClapTrap& setAttackDamage(unsigned int attackDamage);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	unsigned int _hitPoints; // Health of ClapTrap
	unsigned int _energyPoints; // Energy of ClapTrap to attack or repair
	unsigned int _attackDamage; // Amount of damage points it attacks with
	
};

#endif
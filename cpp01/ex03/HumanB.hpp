/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:54:55 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 18:35:15 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
	
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	attack() const;

private:
	std::string	_name;
	Weapon*		_weapon;

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:52:46 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 23:12:10 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name ) {
	Zombie* ptr_zombie = new Zombie(name);
	return ptr_zombie;
	// return new Zombie(name) // works
}
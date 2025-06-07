/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:53:40 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 23:17:34 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	Zombie* ptr_zombie00 = newZombie("Heap Zombie 00");

	{
		randomChump("Random Chump 00 : Stack Zombie 00");
	}
	
		Zombie* ptr_zombie01 = newZombie("Heap Zombie 01");
		ptr_zombie01->announce();
	
	{
		randomChump("Random Chump 01: Stack Zombie 01");
	}

	randomChump("Stack Zombie 02");
	
	delete ptr_zombie00;
	delete ptr_zombie01;
	return 0;
}
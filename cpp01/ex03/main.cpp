/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:16:02 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 18:49:57 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {
	
	std::cout << std::endl << "Test 1:" << std::endl << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << std::endl << "Test 2:" << std::endl << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		HumanB jim("Jim");

		bob.attack();
		jim.attack();
		
		club.setType("some other type of club");
		jim.setWeapon(club);
		
		bob.attack();
		jim.attack();
	}
	
	std::cout << std::endl << "Test 3:" << std::endl << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		HumanB jim("Jim");

		bob.attack();
		jim.attack();
		club.setType("some other type of club");
		
		bob.attack();
		jim.attack();
	}
	
	return 0;
}
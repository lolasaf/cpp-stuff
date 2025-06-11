/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:09:08 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/10 22:02:02 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


#define CYAN_BOLD "\033[1;36m"
#define RESET     "\033[0m"

int main(void) {

	{
		std::cout << CYAN_BOLD << "\n--- Basic Test ---\n" << RESET;
		ClapTrap bot("Clappy");
		bot.attack("Target A");
		bot.takeDamage(5);
		bot.beRepaired(3);
		bot.setAttackDamage(10);
		bot.attack("Target B");
	}

	{
		std::cout << CYAN_BOLD << "\n--- Energy Depletion Test ---\n" << RESET;
		ClapTrap bot("Exhausto");
		bot.setAttackDamage(5);
		for (int i = 0; i < 11; ++i)
			bot.attack("Dummy");
		bot.beRepaired(5); // no energy
	}

	{
		std::cout << CYAN_BOLD << "\n--- Zero Hit Points Test ---\n" << RESET;
		ClapTrap bot("Fragile");
		bot.setAttackDamage(5);
		bot.takeDamage(10);  // HP drop to 0
		bot.attack("Nope");  // fails
		bot.beRepaired(2);   // fails
	}

	{
		std::cout << CYAN_BOLD << "\n--- No -ve Damage Test ---\n" << RESET;
		ClapTrap bot("Exacto");
		bot.takeDamage(10);  // HP = 0
		bot.takeDamage(5);   // should not drop under 0
	}

	{
		std::cout << CYAN_BOLD << "\n--- Copy Constructor Test ---\n" << RESET;
		ClapTrap original("Original");
		ClapTrap copy(original);
		copy.attack("CloneTarget");
	}

	{
		std::cout << CYAN_BOLD << "\n--- Copy Assignment Test ---\n" << RESET;
		ClapTrap botA("A");
		ClapTrap botB("B");
		botB = botA;
		botB.attack("TargetFromA");
	}

	{
    std::cout << CYAN_BOLD << "\n--- Setter Test ---\n" << RESET;
    ClapTrap bot;
    bot.setName("SetterBot").setHitPoints(50).setEnergyPoints(20).setAttackDamage(15);
    bot.attack("Target X");
	}

	return 0;
}

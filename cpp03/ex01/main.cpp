/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:09:08 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/10 23:43:15 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

int main() {
    std::cout << CYAN << "\n--- ScavTrap Constructor Test ---\n" << RESET;
    {
        ScavTrap scav("GateKeeper");
    }

    std::cout << CYAN << "\n--- ScavTrap Attack Test ---\n" << RESET;
    {
        ScavTrap scav("Attacker");
        scav.attack("Enemy Bot");
    }

    std::cout << CYAN << "\n--- ScavTrap Gate Keeper Mode Test ---\n" << RESET;
    {
        ScavTrap scav("Guardian");
        scav.guardGate();
    }

    std::cout << CYAN << "\n--- ScavTrap Full Interaction Test ---\n" << RESET;
    {
        ScavTrap scav("BattleBot");
        scav.attack("Target 1");
        scav.takeDamage(40);
        scav.beRepaired(30);
        scav.guardGate();
    }

    std::cout << CYAN << "\n--- ScavTrap Copy Constructor & Assignment Test ---\n" << RESET;
    {
        ScavTrap original("Original");
        ScavTrap copy(original);
        ScavTrap another("Another");
        another = original;
    }

    return 0;
}

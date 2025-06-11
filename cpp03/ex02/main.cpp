/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:09:08 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 00:16:01 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

int main() {

	std::cout << CYAN << "\n--- FragTrap Basic Test ---\n" << RESET;
    {
        FragTrap frag("Fraggy");
        frag.attack("Target X");
        frag.takeDamage(25);
        frag.beRepaired(15);
        frag.highFivesGuys();
    }

    std::cout << CYAN << "\n--- FragTrap Copy Test ---\n" << RESET;
    {
        FragTrap frag1("CloneMe");
        FragTrap frag2(frag1);
        FragTrap frag3("AnotherOne");
        frag3 = frag1;
    }

    return 0;
}

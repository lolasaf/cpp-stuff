/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:34:41 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 23:23:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int ac, char *av[]) {
	
	Harl h;
	int option;

	if (ac == 1)
		return(std::cout << "Nothing to complain about." << std::endl, 1);
	if (ac != 2)
		return(std::cout << "!!! You cannot be complaining this much !!!" << std::endl, 1);
	std::string level = av[1];
	
	if (level == "DEBUG") option = 1;
	else if (level == "INFO") option = 2;
	else if (level == "WARNING") option = 3;
	else if (level == "ERROR") option = 4;
	else option = 5;

	switch (option) {
		case 1:
			h.complain("DEBUG");
		case 2:
			h.complain("INFO");
		case 3:
			h.complain("WARNING");
		case 4:
			h.complain("ERROR");
			break;
		default:
			h.complain("");
	}

	return 0;
}
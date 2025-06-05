/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:35:02 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/03 23:01:15 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++) {	
		std::string str = av[i];
		for(int j = 0; j < (int) str.length(); j++ ) {
			std::cout << (char)std::toupper(str[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}

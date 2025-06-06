/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:38:26 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 00:58:39 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	
	int N = 10;
	Zombie* horde = zombieHorde(N, "MUSTEATBRAINZ");
	
	for(int i = 0; i < N; i++) {
		std::cout << "Zombie index: " << i << " | ";
		horde[i].announce();
	}

	delete[] horde;
	return 0;	
}
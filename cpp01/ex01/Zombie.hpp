/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:25:37 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 00:56:48 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	setName( std::string name );
	void	announce( void );

private:
	std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
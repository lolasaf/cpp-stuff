/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:41:11 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 23:28:43 by wel-safa         ###   ########.fr       */
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

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
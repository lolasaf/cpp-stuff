/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:01:33 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/06 01:37:29 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout	<< "The memory address of the str        = " << &str << std::endl
				<< "The memory address held by stringPTR = " << stringPTR << std::endl
				<< "The memory address held by stringREF = " << &stringREF << std::endl;

	std::cout	<< "The value of the str                 = " << str << std::endl
				<< "The value of the stringPTR           = " << stringPTR << std::endl
				<< "The value of the stringREF           = " << stringREF << std::endl;

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:03:21 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/12 14:16:21 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char *av[]) {

	if (ac != 4) 
		return(std::cerr << "Usage: ./sedIs4LoserZ <filename> <s1> <s2>" << std::endl, 1);

	std::string filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (s1.empty())
		return(std::cerr << "Usage: ./sedIs4LoserZ <filename> <s1> <s2>" << std::endl << "<s1> is empty" << std::endl, 1);

	std::ifstream infile(filename.c_str());
	if (!infile) {
    	std::cerr << "Failed to open <" << filename << ">" << std::endl;
		return 1;
	}

	
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
    	std::cerr << "Failed to create " << filename << ".replace" << std::endl;
		return 1;
	}

	std::string	line;
	size_t pos = 0;
	while (std::getline(infile, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:41:37 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:07:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default constructor called for Brain" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = "";
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Copy operator called for Brain" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Destructor called for Brain" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		std::cerr << "Invalid idea index: " << index << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas[index];
	else {
		std::cerr << "Invalid idea index: " << index << std::endl;
		return "";
	}
}

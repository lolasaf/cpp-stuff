/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:07:51 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 17:36:26 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"


int main()
{

	std::cout << CYAN << "\n--- Animals Basic Test ---\n" << RESET;
    {
	
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << CYAN << "\n--- Wrong Animal/Cat Test ---\n" << RESET;
    {
	
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();	
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the animal sound :(
		meta->makeSound();

		delete meta;
		delete i;
	}

	std::cout << CYAN << "\n--- Stack Allocation Test ---\n" << RESET;
	{
		Dog d;
		Cat c;
		std::cout << d.getType() << std::endl;
		d.makeSound();
		std::cout << c.getType() << std::endl;
		c.makeSound();
	}

	std::cout << CYAN << "\n--- Copy Constructor Test ---\n" << RESET;
	{
		Dog original;
		Dog copy = original;

		Cat catOriginal;
		Cat catCopy(catOriginal);

		copy.makeSound();
		catCopy.makeSound();
	}

	std::cout << CYAN << "\n--- Mixed Array of Animals Test ---\n" << RESET;
	{
		const Animal* zoo[4];
		for (int i = 0; i < 2; ++i)
			zoo[i] = new Dog();
		for (int i = 2; i < 4; ++i)
			zoo[i] = new Cat();

		for (int i = 0; i < 4; ++i)
			zoo[i]->makeSound();

		for (int i = 0; i < 4; ++i)
			delete zoo[i];
	}

	std::cout << CYAN << "\n--- Virtual Destructor Test ---\n" << RESET;
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		delete dog; // Should call Dog destructor THEN Animal destructor
		delete cat; // Should call Cat destructor THEN Animal destructor
	}

	return 0;
}
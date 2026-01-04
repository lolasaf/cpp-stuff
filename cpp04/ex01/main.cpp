/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:21:39 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/11 20:21:41 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

int main() {
    std::cout << CYAN << "\n--- Basic Polymorphic Deletion Test ---\n" << RESET;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j; // should not leak
        delete i;
    }

    std::cout << CYAN << "\n--- Deep Copy Test (Dog) ---\n" << RESET;
    {
        Dog dog1;
        dog1.getBrain()->setIdea(0, "Chase the mailman");
        Dog dog2 = dog1; // deep copy
        dog2.getBrain()->setIdea(1, "Guard the house");

        std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;
    }

    std::cout << CYAN << "\n--- Deep Copy Test (Cat) ---\n" << RESET;
    {
        Cat cat1;
        cat1.getBrain()->setIdea(0, "Climb curtain");
        Cat cat2(cat1); // deep copy
        cat2.getBrain()->setIdea(1, "Nap in sunbeam");

        std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
        std::cout << "cat2 idea[1]: " << cat2.getBrain()->getIdea(1) << std::endl;
    }

    std::cout << CYAN << "\n--- Array of Animals (Polymorphism + Cleanup) ---\n" << RESET;
    {
        Animal* zoo[4];
        for (int i = 0; i < 2; ++i)
            zoo[i] = new Dog();
        for (int i = 2; i < 4; ++i)
            zoo[i] = new Cat();

        for (int i = 0; i < 4; ++i)
            zoo[i]->makeSound();

        for (int i = 0; i < 4; ++i)
            delete zoo[i];
    }

    return 0;
}

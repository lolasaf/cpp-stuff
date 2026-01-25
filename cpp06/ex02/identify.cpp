/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:28:47 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/25 19:45:38 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void) {
    // Generate a random number between 0 and 2
    int random = std::rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (p == NULL) {
		std::cout << "NULL pointer" << std::endl;
		return;
	}

    // Dynamic cast uses RTTI to determine the type of the object
    // RTTI is Runtime Type Information
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e) {
        // Not A
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
            return;
        }
        catch (const std::exception &e) {
            // Not B
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
                return;
            }
            catch (const std::exception &e) {
                // Not C
                std::cout << "Unknown type" << std::endl;
                return;
            }
        }
    }
}
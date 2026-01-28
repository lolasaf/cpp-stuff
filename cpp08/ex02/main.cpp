/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:09:16 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/28 20:39:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "== Subject MutantStack Test ==" << std::endl;

	std::cout << "-- MutantStack --" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
    
	{
		std::cout << "-- std::list --" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
    
	{
		std::cout << "== Reverse Iteration Test ==" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite) {
			std::cout << *rit << std::endl;
			++rit;
	    }
	}	

	{
		std::cout << "== Const Iterator Test ==" << std::endl;
		const MutantStack<int> constStack = mstack;
		MutantStack<int>::const_iterator cit = constStack.begin();
		MutantStack<int>::const_iterator cite = constStack.end();
		while (cit != cite) {
			std::cout << *cit << std::endl;
			++cit;
		}
	}
	
	{
		std::cout << "== String MutantStack Test ==" << std::endl;
		MutantStack<std::string> stringStack;
		stringStack.push("Hello");
		stringStack.push("MutantStack");
		for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}

	{
		std::cout << "== Copy Constructor Test ==" << std::endl;
		MutantStack<int> copy = mstack;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}
	
    return 0;
}

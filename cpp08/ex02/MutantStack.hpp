/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:09:12 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/28 20:27:40 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>


template <typename T>
class MutantStack : public std::stack<T> {
public:

	// Orthodox canonical form
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack& other) { *this = other; };
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
			// or this->c = other.c; // copy underlying stack container
		}
		return *this;
	};
	~MutantStack() {};
	
	// iterators typedefs
	typedef typename std::stack<T>::container_type				container_type;
	typedef typename container_type::iterator					iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;
	
	// iterator methods
	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };
	const_iterator begin() const { return this->c.begin(); };
	const_iterator end() const { return this->c.end(); };
	reverse_iterator rbegin() { return this->c.rbegin(); };
	reverse_iterator rend() { return this->c.rend(); };
	const_reverse_iterator rbegin() const { return this->c.rbegin(); };
	const_reverse_iterator rend() const { return this->c.rend(); };
	
	// All std::stack methods are inherited: push, pop, top, size, empty
	// We can access the underlying container via this->c
};

#endif

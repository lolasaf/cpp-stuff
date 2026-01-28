/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:09:12 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/28 23:16:38 by wel-safa         ###   ########.fr       */
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
	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();
	
	// iterators typedefs
	typedef typename std::stack<T>::container_type				container_type;
	typedef typename container_type::iterator					iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;
	
	// iterator methods
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	
	// All std::stack methods are inherited: push, pop, top, size, empty
	// We can access the underlying container via this->c
};

#include "MutantStack.tpp"

#endif


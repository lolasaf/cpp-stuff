/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:06 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/08 00:44:44 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define VERBOSE false

class Fixed {

public:
	Fixed(); // constructor
	Fixed(const int& value);
	Fixed(const float& value);
	Fixed(const Fixed& other); // copy constructor
	
	~Fixed();
	
	Fixed&	operator=(const Fixed& other); // copy assignment operator

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	
	Fixed&	operator++();		// Pre-increment
	Fixed	operator++(int);	// Post-increment
	Fixed&	operator--();		// Pre-decrement
	Fixed 	operator--(int);	// Post-decrement

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	float	toFloat(void) const;
	int		toInt(void) const;

	int 	getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream& operator <<(std::ostream& out, const Fixed& fixed);

#endif
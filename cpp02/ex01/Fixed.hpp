/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:06 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/07 20:27:27 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	Fixed(); // constructor
	Fixed(const int& value);
	Fixed(const float& value);
	Fixed(const Fixed& other); // copy constructor
	Fixed& operator=(const Fixed& other); // copy assignment operator
	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream& operator <<(std::ostream& out, const Fixed& fixed);

#endif
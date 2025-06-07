/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:06 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/07 19:57:07 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
 
class Fixed {

public:
	Fixed(); // constructor
	Fixed(const Fixed& other); // copy constructor
	Fixed& operator=(const Fixed& other); // copy assignment operator
	~Fixed();

	int getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawBits;
	static const int	_fractionalBits;
};

#endif
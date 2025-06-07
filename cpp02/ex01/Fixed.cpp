/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:49:24 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/07 21:10:42 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // check if they are not the same object by address
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

Fixed::Fixed(const int& value) {
	std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << Fixed::_fractionalBits;
}

Fixed::Fixed(const float& value) {
	std::cout << "Float constructor called" << std::endl;
    this->_rawBits = (int) roundf(value * (1 << Fixed::_fractionalBits));
}

float Fixed::toFloat() const {
    return (float)this->_rawBits / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt() const {
    return this->_rawBits >> Fixed::_fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

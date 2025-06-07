/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:49:24 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/08 00:45:58 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawBits(0) {
	if (VERBOSE)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    this->_rawBits = other.getRawBits();
	if (VERBOSE)
    	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (VERBOSE)
		std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // check if they are not the same object by address
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
	if (VERBOSE)
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
	if (VERBOSE)
		std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << Fixed::_fractionalBits;
}

Fixed::Fixed(const float& value) {
	if (VERBOSE)
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

bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed add;
	add._rawBits = this->_rawBits + other._rawBits;
	return add;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed subst;
	subst._rawBits = this->_rawBits - other._rawBits;
	return subst;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed mult;
	mult._rawBits = (this->_rawBits * other._rawBits) >> Fixed::_fractionalBits;
	return mult;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed div;
	div._rawBits = (this->_rawBits << Fixed::_fractionalBits)/ other._rawBits;
	return div;
}

Fixed& Fixed::operator++() {
	this->_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_rawBits += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
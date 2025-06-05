/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:53:24 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 16:44:44 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(const std::string& firstName) {
	this->_firstName = firstName;
	return;
}

void	Contact::setLastName(const std::string& lastName) {
	this->_lastName = lastName;
	return;
}

void	Contact::setNickName(const std::string& nickName) {
	this->_nickName = nickName;
	return;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->_phoneNumber = phoneNumber;
	return;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->_darkestSecret = darkestSecret;
	return;
}

std::string	Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string	Contact::getNickName(void) const {
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

// Contact::Contact( void ) {
// 	std::cout << "Constructor called" << std::endl;

// 	this->foo = 42; // this is a pointer of the current instance
// 	std::cout << "this->foo: " << this->foo << std::endl;
	
// 	this->bar();

// 	return;
// }

// Contact::~Contact( void ) {
// 	std::cout << "Destructor called" << std::endl;
// 	return;
// }

// void	Contact::bar( void ) {
// 	std::cout << "Member function bar called" << std::endl;
// 	return ;
// }
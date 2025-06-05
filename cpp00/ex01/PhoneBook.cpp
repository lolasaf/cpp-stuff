/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:34:55 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 19:15:14 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : totalContacts(0) {
	// this->totalContacts = 0; replaced by initializer list
}

void	PhoneBook::addContact(const std::string& firstName,
					const std::string& lastName,
					const std::string& nickName,
					const std::string& phoneNumber,
					const std::string& darkestSecret) {
	
	Contact newContact;
	int		index;
	
	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickName(nickName);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);
	totalContacts++;
	index = (totalContacts - 1) % 8;
	this->contacts[index] = newContact;
}

/*
*Printing Phonebook in this format with spaces instead of (_) :
*_________1|_____Walaa|_El Safadi|LolaEbola.
*/
void	PhoneBook::printPhoneBook(void) const {
	
	std::cout	<< std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << std::endl;

	if (this->totalContacts == 0)
	{
		std::cout << std::setw(43) << std::right << "Empty Phonebook" << std::endl;
		return;
	}
	for (int i = 0; i < this->totalContacts && i < 8; i++) {
		std::cout	<< std::setw(10) << std::right
					<< i + 1 << "|"
					<< std::setw(10) << std::right
					<< truncate(this->contacts[i].getFirstName()) << "|"
					<< std::setw(10) << std::right
					<< truncate(this->contacts[i].getLastName()) << "|"
					<< std::setw(10) << std::right
					<< truncate(this->contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::printContact(int index) const {
	
	if (index < 1 || index > 8)
	{
		std::cout << "Index is not within range (1, 8)" << std::endl;
		return;
	}
	if (index > totalContacts)
	{
		std::cout << "No contact set at this index" << std::endl;
		return;
	}
	std::cout	<< std::endl
				<< "First Name: " << this->contacts[index - 1].getFirstName() << std::endl
				<< "Last Name: " << this->contacts[index - 1].getLastName() << std::endl
				<< "Nick Name: " << this->contacts[index - 1].getNickName() << std::endl
				<< "Phone Number: " << this->contacts[index - 1].getPhoneNumber() << std::endl
				<< "Darkest Secret: " << this->contacts[index - 1].getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncate(const std::string& str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:57:21 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 19:09:26 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

std::string	promptNonEmpty(const std::string& prompt) {

	std::string input;
	
	while (input.empty() || input.find_first_not_of(' ') == std::string::npos) {
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return input;
}

bool isAllDigits(const std::string& str) {
	
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (std::isdigit(str[i]) == false)
			return false;
	}
	return true;
}

std::string	promptDigits(const std::string& prompt) {

	std::string input;
	
	input = promptNonEmpty(prompt);
	while (isAllDigits(input) == false) {
		std::cout << "Input must be all digits" << std::endl;
		input = promptNonEmpty(prompt);
	}
	return input;
}

void	handleADD(PhoneBook& myPhoneBook) {
	
	std::string firstName = promptNonEmpty("Enter First Name: ");
	std::string lastName = promptNonEmpty("Enter Last Name: ");
	std::string nickName = promptNonEmpty("Enter Nickname: ");
	std::string phoneNumber = promptDigits("Enter Phone Number: ");
	std::string darkestSecret = promptNonEmpty("Enter Darkest Secret: ");
	
	myPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	
	return;
}

void	handleSEARCH(PhoneBook& myPhoneBook) {
	
	myPhoneBook.printPhoneBook();
	std::string indexstr = promptDigits("Enter index of contact to display: ");
	int index = atoi(indexstr.c_str());
	myPhoneBook.printContact(index);
}

int	main(void) {
	
	PhoneBook	myPhoneBook;
	std::string	input;

	std::cout << "Commands to use your phonebook: ADD, SEARCH, EXIT" << std::endl;
	while(1)
	{
		std::cout << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			handleADD(myPhoneBook);
		else if (input == "SEARCH")
			handleSEARCH(myPhoneBook);
		else if (input == "EXIT")
			break;
	}
	return 0;
}

// int	main() {
// 	Contact mycontact; // instance of contact

// 	mycontact.foo = 32;
// 	std::cout << "instance.foo :" << mycontact.foo << std::endl;
	
// 	return 0;
// }
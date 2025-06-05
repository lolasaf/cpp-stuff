/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:35:18 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 18:12:56 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook {
	
private:

	Contact contacts[8];
	int		totalContacts;
	
	std::string truncate(const std::string& str) const;
	
public:
	
	PhoneBook(void);
	
	void	addContact(const std::string& firstName,
					const std::string& lastName,
					const std::string& nickName,
					const std::string& phoneNumber,
					const std::string& darkestSecret);

	void	printPhoneBook(void) const;
	void	printContact(int index) const;
};

#endif
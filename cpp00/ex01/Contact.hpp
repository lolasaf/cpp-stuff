/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:43:22 by wel-safa          #+#    #+#             */
/*   Updated: 2025/06/05 18:12:09 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

public:

	void		setFirstName(const std::string& firstName);
	void		setLastName(const std::string& lastName);
	void		setNickName(const std::string& nikName);
	void		setPhoneNumber(const std::string& phoneNumber);
	void		setDarkestSecret(const std::string& darkestSecret);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
	
private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string _darkestSecret;
};


/*class Contact {
	
public:

	int public_attribute;
	int foo; // member attribute, you may use with your instance

	// constructor
	Contact( void );
	// destructor
	~Contact( void );

	void	bar( void ); // member function

private:
	// this will be internal to my class
	
	int	_private_attribute;
	
	void _privatebar( void ) const; 
	// const means this function cannot change attributes from your class
	
};*/

#endif
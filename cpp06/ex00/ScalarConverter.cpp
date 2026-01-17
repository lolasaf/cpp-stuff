/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:26:49 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/17 23:45:22 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>


void printChar(int c) {
	if (isascii(c)) {
		if (isprint(c)) {
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		} 
		else {
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
}


void ScalarConverter::convert(const std::string& literal) {

	// Check Pseudo-literals and handle conversions
	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return;
	}

	// Input: char 'a'
	{
		char c;
		if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
			c = literal[1];
			printChar(c);
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
			return;
		}
		else if (literal.length() == 1 && !isdigit(literal[0])) {
			c = literal[0];
			printChar(c);
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
			return;
		}
	}
	
	// Input: integer
	{
		char* endptr;
		long val = std::strtol(literal.c_str(), &endptr, 10);
		if (*endptr == '\0' && endptr != literal.c_str()) {
			// valid numeric input

			// within int min and max
			if (val >= INT_MIN && val <= INT_MAX) {
				printChar(val);
				std::cout << "int: " << static_cast<int>(val) << std::endl;
				std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(val) << "f" << std::endl;
				std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(val) << std::endl;
				return;
			}
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			
			// float and double if int overflow
			errno = 0;
			float f = std::strtof(literal.c_str(), &endptr);
			if (errno == ERANGE) {
				std::cout << "float: impossible" << std::endl;
			}
			else if (*endptr == '\0' && endptr != literal.c_str()) {
				std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
			}
			else {
				std::cout << "float: impossible" << std::endl;
			}
			errno = 0;
			double d = std::strtod(literal.c_str(), &endptr);
			if (errno == ERANGE) {
				std::cout << "double: impossible" << std::endl;
			}
			else if (*endptr == '\0' && endptr != literal.c_str()) {
				std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
			}
			else {
				std::cout << "double: impossible" << std::endl;
			}
			return;
		}
	}
	
	// input: float
	{
		char* endptr;
		float f = std::strtof(literal.c_str(), &endptr);
		if (endptr != literal.c_str() && *endptr == 'f' && 
			endptr == literal.c_str() + literal.length() - 1) {
			// valid float input
			// do conversions and print
			
			// convert to char and int
			if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX)) {
				printChar(static_cast<int>(f));
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			} 
			else {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}
			
			std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
			
			return;
		}
	}

	// input: double
	{
		char* endptr;
		double d = std::strtod(literal.c_str(), &endptr);
		if (*endptr == '\0' && endptr != literal.c_str()) {
			// valid double input
			// do conversions and print

			// convert to char and int
			if (d >= INT_MIN && d <= INT_MAX) {
				printChar(static_cast<int>(d));
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			} 
			else {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}

			// convert to float
			if (d >= -FLT_MAX && d <= FLT_MAX) {
				std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
			} 
			else {
				std::cout << "float: impossible" << std::endl;
			}
			std::cout << "double: " << d << std::endl;
			return;
		}
	}
	
	// if none matched
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return;
}

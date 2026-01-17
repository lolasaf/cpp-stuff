/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:22:41 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/17 23:04:31 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cmath>
# include <iostream>
# include <climits>
# include <cstdlib>
# include <cerrno>
# include <cfloat>

class ScalarConverter {
public:
	static void convert(const std::string& literal);

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
};

#endif

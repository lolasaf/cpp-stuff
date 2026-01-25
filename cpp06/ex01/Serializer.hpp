/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:05:50 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/25 23:06:35 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
};

#endif

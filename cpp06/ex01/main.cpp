/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:05:50 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/25 23:06:35 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {

	Data data;
	data.sku_id = 1234567890;
	data.product_name = "Test Product";
	data.product_price = 99.99;

	std::cout << "Original Data:" << std::endl;
	std::cout << "  sku_id: " << data.sku_id << std::endl;
	std::cout << "  product_name: " << data.product_name << std::endl;
	std::cout << "  product_price: " << data.product_price << std::endl;
	std::cout << "  address: " << &data << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  sku_id: " << deserialized->sku_id << std::endl;
	std::cout << "  product_name: " << deserialized->product_name << std::endl;
	std::cout << "  product_price: " << deserialized->product_price << std::endl;
	std::cout << "  address: " << deserialized << std::endl;
	std::cout << std::endl;

	if (deserialized == &data) {
		std::cout << "✓ SUCCESS: Pointers match! Serialization/deserialization works correctly." << std::endl;
	} else {
		std::cout << "✗ FAIL: Pointers do not match!" << std::endl;
		return 1;
	}

	return 0;
}

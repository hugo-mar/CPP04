/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:08:10 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/22 18:10:56 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type("Generic") {
	std::cout << "An abstract animal was constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	: type(other.type) {
	std::cout << "An abstract animal was copy constructed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "An abstract animal was copy assigned" << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "An abstract animal was destructed" << std::endl;
}

std::string	AAnimal::getType() const {
	return type;
}
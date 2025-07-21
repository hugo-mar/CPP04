/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:18:42 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 19:55:13 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("Generic") {
	std::cout << "A WrongAnimal was constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type) {
	std::cout << "A WrongAnimal was copy constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "A WrongAnimal was copy assigned" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "A WrongAnimal was destructed" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "* Ambiguous WrongAnimal noise *" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return type;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:00:00 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 17:55:13 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("Generic") {
	std::cout << "An animal was constructed" << std::endl;
}

Animal::Animal(const Animal& other)
	: type(other.type) {
	std::cout << "An animal was copy constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "An animal was copy assigned" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "An animal was destructed" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "* Ambiguous animal noise *" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}
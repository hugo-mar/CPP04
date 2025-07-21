/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:26:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 19:00:11 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "A dog was constructed" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other) {
	std::cout << "A dog was copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A dog was copy assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "A dog was destructed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}
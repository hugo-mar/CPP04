/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:00:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 19:36:54 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "A cat was constructed" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other) {
	std::cout << "A cat was copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A cat was copy assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "A cat was destructed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}
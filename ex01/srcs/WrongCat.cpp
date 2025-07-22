/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:34:30 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 19:36:29 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "A WrongCat was constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other) {
	std::cout << "A WrongCat was copy constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "A WrongCat was copy assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "A WrongCat was destructed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "meow??? (but wrongly ignored)" << std::endl;
}

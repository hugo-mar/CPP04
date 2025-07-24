/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:40:36 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 16:11:46 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Materia constructed" << std::endl;
}

Ice::Ice(Ice const & other) : AMateria(other) {
	std::cout << "Ice Materia copy constructed" << std::endl;
}

Ice & Ice::operator=(Ice const & other) {
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Ice Materia copy assigned" << std::endl;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice Materia destructed" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


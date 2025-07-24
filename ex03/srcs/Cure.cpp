/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:02:23 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 16:12:10 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Materia constructed" << std::endl;
}

Cure::Cure(Cure const & other) : AMateria(other) {
	std::cout << "Cure Materia copy constructed" << std::endl;
}

Cure & Cure::operator=(Cure const & other) {
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Cure Materia copy assigned" << std::endl;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure Materia destructed" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

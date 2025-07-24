/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:30:31 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 16:13:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const& type)
	: _type(type) {
	std::cout << "Abstract Materia constructed" << std::endl;
}

AMateria::AMateria(AMateria const& other)
	: _type(other._type) {
	std::cout << "Abstract Materia copy constructed" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Abstract Materia copy assigned" << std::endl;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Abstract Materia destructed" << std::endl;
}

std::string const&	AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target){
	std::cout << "* sends materia to " << target.getName() << " *" << std::endl;
}
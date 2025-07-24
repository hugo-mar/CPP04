/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:08:41 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 13:04:01 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		_templates[i] = 0;
	}
	std::cout << "Materia source constructed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& other) {
	for (int i = 0; i < 4; ++i) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = 0;
	}
	std::cout << "MateriaSource copy constructed" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (_templates[i])
				delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = 0;
		}
	}
	std::cout << "MateriaSource copy assigned" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (_templates[i])
			delete _templates[i];
	}
	std::cout << "MateriaSource destructed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (!_templates[i]) {
			_templates[i] = m->clone();
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; ++i) {
		if (_templates[i]) {
			if (_templates[i]->getType() == type)
				return _templates[i]->clone();	
		}
	}
	return 0;
}
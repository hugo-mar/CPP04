/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:29:19 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 16:12:49 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const& name)
	: _name(name) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
	std::cout << "Character constructed: " << _name << std::endl;
}

Character::Character(Character const& other)
	: _name(other._name) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
	copyInventory(other);
	std::cout << "Character copy constructed: " << _name << std::endl;
}

Character& Character::operator=(Character const& other) {
	if (this != &other) {
		_name = other._name;
		clearInventory();
		copyInventory(other);
	}
	std::cout << "Character copy assigned: " << _name << std::endl;
	return *this;
}

Character::~Character() {
	clearInventory();
	std::cout << "Character destructed: " << _name << std::endl;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " in slot " << i << " (" << _name << ")" << std::endl;
			return;
		}
	}
	std::cout << "No space to equip materia (" << _name << ")" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx]) {
		std::cout << "Unequipped materia from slot " << idx << " (" << _name << ")" << std::endl;
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}

void Character::clearInventory() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = 0;
		}
	}
}

void Character::copyInventory(Character const& other) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

AMateria*	Character::getMateria(int idx) const {
	return _inventory[idx];
}

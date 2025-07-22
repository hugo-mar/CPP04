/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:26:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/22 18:24:23 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	_brain = new Brain;
	std::cout << "A dog was constructed" << std::endl;
}

Dog::Dog(const Dog& other)
	: AAnimal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "A dog was copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "A dog was copy assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "A dog was destructed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}

std::string Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}

void	Dog::setIdea(int index, const std::string& idea) {
	_brain->setIdea(index, idea);
}

Brain* Dog::getBrain() {
	return _brain;
}

const Brain* Dog::getBrain() const {
	return _brain;
}
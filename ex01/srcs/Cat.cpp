/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:00:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/22 16:21:19 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	_brain = new Brain;
	std::cout << "A cat was constructed" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other) {
	_brain = new Brain(*other._brain);
	std::cout << "A cat was copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "A cat was copy assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "A cat was destructed" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "meow meow" << std::endl;
}

std::string	Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea) {
	_brain->setIdea(index, idea);
}

Brain* Cat::getBrain() {
	return _brain;
}

const Brain* Cat::getBrain() const {
	return _brain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:39:18 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/21 20:24:58 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Correct Hierarchy ===" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "I'm a " << meta->getType() << " and when I speak I make: ";
	meta->makeSound();

	std::cout << "I'm a " << j->getType() << " and when I speak I make: ";
	j->makeSound();

	std::cout << "I'm a " << i->getType() << " and when I speak I make: ";
	i->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "=== Wrong Hierarchy ===" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "I'm a " << wrongMeta->getType() << " and when I speak I make: ";
	wrongMeta->makeSound();

	std::cout << "I'm a " << wrongCat->getType() << " and when I speak I make: ";
	wrongCat->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl << "=== Copy & Assignment Tests ===" << std::endl;

	{
		std::cout << "\n--- Animal ---" << std::endl;
		Animal a1;
		Animal a2(a1);
		Animal a3;
		a3 = a2;
	}

	{
		std::cout << "\n--- Dog ---" << std::endl;
		Dog d1;
		Dog d2(d1);
		Dog d3;
		d3 = d2;
	}
	
	{
		std::cout << "\n--- Cat ---" << std::endl;
		Cat c1;
		Cat c2(c1);
		Cat c3;
		c3 = c2;
	}

	{
		std::cout << "\n--- WrongAnimal ---" << std::endl;
		WrongAnimal wa1;
		WrongAnimal wa2(wa1);
		WrongAnimal wa3;
		wa3 = wa2;
	}

	{
		std::cout << "\n--- WrongCat ---" << std::endl;
		WrongCat wc1;
		WrongCat wc2(wc1);
		WrongCat wc3;
		wc3 = wc2;
	}


	return 0;
}

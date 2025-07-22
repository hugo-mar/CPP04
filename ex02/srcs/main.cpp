/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:39:18 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/22 18:53:27 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {

	// AAnimal test; // Abstract class – won't compile (uncomment during evaluation)

	std::cout << "=== Creating array of AAnimal* ===\n";
	const int size = 4;
	AAnimal* animals[size];

	for (int i = 0; i < size; ++i) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Polymorphic behavior test ===\n";
	for (int i = 0; i < size; ++i) {
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== Deep copy test: Dog ===\n";
	Dog originalDog;
	originalDog.setIdea(0, "Chase the cat");
	originalDog.setIdea(1, "Dig a hole");

	Dog copiedDog(originalDog);
	copiedDog.setIdea(0, "Ignore the cat");

	std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << "\n";
	std::cout << "Original Dog idea[1]: " << originalDog.getIdea(1) << "\n";
	std::cout << "Copied Dog idea[0]:   " << copiedDog.getIdea(0) << "\n";
	std::cout << "Copied Dog idea[1]:   " << copiedDog.getIdea(1) << "\n";

	std::cout << "\n=== Deep copy test: Cat ===\n";
	Cat originalCat;
	originalCat.setIdea(0, "Scratch the sofa");
	originalCat.setIdea(1, "Climb the curtains");

	Cat copiedCat(originalCat);
	copiedCat.setIdea(1, "Sleep in the sun");

	std::cout << "Original Cat idea[0]: " << originalCat.getIdea(0) << "\n";
	std::cout << "Original Cat idea[1]: " << originalCat.getIdea(1) << "\n";
	std::cout << "Copied Cat idea[0]:   " << copiedCat.getIdea(0) << "\n";
	std::cout << "Copied Cat idea[1]:   " << copiedCat.getIdea(1) << "\n";

	std::cout << "\n=== Cleaning up ===\n";
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}

	std::cout << "\n=== Program finished ===\n";
	return 0;
}


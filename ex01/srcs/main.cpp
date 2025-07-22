/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:39:18 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/22 17:06:17 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Creating array of Animals ===\n";
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size; ++i) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Animals making sounds ===\n";
	for (int i = 0; i < size; ++i) {
		animals[i]->makeSound();
	}

	std::cout << "\n=== Testing deep copy (Dog) ===\n";
	Dog originalDog;
	originalDog.setIdea(0, "Chase the cat");
	originalDog.setIdea(1, "Dig a hole");

	Dog copiedDog(originalDog);
	copiedDog.setIdea(0, "Ignore the cat");

	std::cout << "Original Dog Idea[0]: " << originalDog.getIdea(0) << "\n";
	std::cout << "Original Dog Idea[1]: " << originalDog.getIdea(1) << "\n";
	std::cout << "Copied Dog Idea[0]: " << copiedDog.getIdea(0) << "\n";
	std::cout << "Copied Dog Idea[1]: " << copiedDog.getIdea(1) << "\n";

	std::cout << "\n=== Testing assignment operator (Dog) ===\n";
	Dog assignedDog;
	assignedDog = originalDog;
	assignedDog.setIdea(1, "Sleep");

	std::cout << "Original Dog Idea[1]: " << originalDog.getIdea(1) << "\n";
	std::cout << "Assigned Dog Idea[1]: " << assignedDog.getIdea(1) << "\n";

	std::cout << "\n=== Testing deep copy (Cat) ===\n";
	Cat originalCat;
	originalCat.setIdea(0, "Scratch the sofa");
	originalCat.setIdea(1, "Nap on the window");

	Cat copiedCat(originalCat);
	copiedCat.setIdea(0, "Ignore the humans");

	std::cout << "Original Cat Idea[0]: " << originalCat.getIdea(0) << "\n";
	std::cout << "Original Cat Idea[1]: " << originalCat.getIdea(1) << "\n";
	std::cout << "Copied Cat Idea[0]: " << copiedCat.getIdea(0) << "\n";
	std::cout << "Copied Cat Idea[1]: " << copiedCat.getIdea(1) << "\n";

	std::cout << "\n=== Testing assignment operator (Cat) ===\n";
	Cat assignedCat;
	assignedCat = originalCat;
	assignedCat.setIdea(1, "Play with the curtains");

	std::cout << "Original Cat Idea[1]: " << originalCat.getIdea(1) << "\n";
	std::cout << "Assigned Cat Idea[1]: " << assignedCat.getIdea(1) << "\n";

	std::cout << "\n=== Deleting animals ===\n";
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}

	std::cout << "\n=== End of program ===\n";
	return 0;
}



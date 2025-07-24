/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:06:20 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 18:39:54 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

// Simple separator for chapters/sections
void separator(const std::string& txt = "") {
    std::cout << "\n======= " << txt << " =======\n";
}

int main() {
    separator("The Forgotten Caverns");
    std::cout << "Alfrin the Wizard ventures into the cavern, facing Gruk the Goblin.\n";
    std::cout << "Both prepare for the unexpected. Let the story unfold...\n";

    separator("Construction phase");
    MateriaSource* spellbook = new MateriaSource();
    AMateria* iceMateria = new Ice();
    AMateria* cureMateria = new Cure();
    spellbook->learnMateria(iceMateria);
    spellbook->learnMateria(cureMateria);
    Character* wizard = new Character("Alfrin the Wizard");
    Character* goblin = new Character("Gruk the Goblin");
    wizard->equip(spellbook->createMateria("ice"));
    wizard->equip(spellbook->createMateria("cure"));

    separator("Chapter 1: The Duel");
    std::cout << "Alfrin raises his staff towards Gruk and hurls a shard of ice.\n";
    std::cout << ">> ";
    wizard->use(0, *goblin); // ice

    std::cout << "Gruk is hit and throws a rock back at Alfrin, wounding him!\n";
    std::cout << "Alfrin utters a healing word to mend his wounds.\n";
    std::cout << ">> ";
    wizard->use(1, *wizard); // cure

    separator("Deep copy magic");
    std::cout << "Suddenly, Gruk the Goblin sheds a scale and... splits in two!\n";
    Character* goblinClone = new Character(*goblin);
    goblinClone->equip(spellbook->createMateria("ice"));
    std::cout << "The goblin clone tries to cast an ice spell, but loses control and injures himself!\n";
    std::cout << ">> ";
    goblinClone->use(0, *wizard);

    separator("Spells on the Floor");
    AMateria* droppedSpell = wizard->getMateria(1); // Cure spell in slot 1
    wizard->unequip(1);
    std::cout << "In the chaos, Alfrin drops a healing spell on the floor.\n";

    // --- USER CHOICE: Does Gruk grab the spell, or is there a leak? ---
    int userChoice = 0;
    do {
        std::cout << "\nWhat does Gruk do?\n";
        std::cout << "  1. Grabs the healing spell and uses it on himself (no memory leak)\n";
        std::cout << "  2. Runs away, leaving the spell on the floor (leak!)\n";
        std::cout << "Choose 1 or 2: ";
        std::cin >> userChoice;
        if (std::cin.fail() || (userChoice != 1 && userChoice != 2)) {
            std::cin.clear();                   // clear error state
            std::cin.ignore(1000, '\n');        // discard bad input
            std::cout << "Invalid input! Please enter 1 or 2 only.\n";
            userChoice = 0;
        }
    } while (userChoice != 1 && userChoice != 2);

    if (userChoice == 1) {
        std::cout << "\nGruk, quick to act, grabs the dropped spell and uses it on himself.\n";
        goblin->equip(droppedSpell);
        std::cout << ">> ";
        goblin->use(0, *goblin); // use cure on self
        // droppedSpell will be deleted by goblin's destructor
    } else {
        std::cout << "\nBut Gruk flees in panic, leaving the healing spell behind... (Leak scenario!)\n";
        // droppedSpell is lost; memory leak!
    }

    separator("Finale");
    std::cout << "The wizard and the goblins eye each other warily, unmoving, for what feels like hours.\n";
    std::cout << "Finally, as the dust settles and the echoes fade, everyone slowly leaves the cavern.\n";
    std::cout << "Only the memory (and maybe a spell or two) remains...\n";

    // -- Clean up (does NOT delete droppedSpell if it's left on the floor!) --
    delete goblinClone;
    delete goblin;
    delete wizard;
    delete spellbook;
    delete iceMateria;
    delete cureMateria;

    separator("End of story");
    std::cout << "All magic is released, and the memory is safe. Or is it? hahahahaha\n";
    return 0;
}



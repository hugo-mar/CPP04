/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:41:34 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 10:42:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria*	_inventory[4];

	void	clearInventory();
	void	copyInventory(Character const& other);

public:
	Character(std::string const& name);
	Character(Character const& other);
	Character& operator=(Character const& other);
	virtual ~Character();

	virtual std::string const&	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

	AMateria*					getMateria(int idx) const;			// Useful to save the address before unequip
	
};

#endif


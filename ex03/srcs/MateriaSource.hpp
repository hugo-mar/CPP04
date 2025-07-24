/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:43:05 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/24 12:05:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _templates[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const& other);
	MateriaSource& operator=(MateriaSource const& other);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);
};

#endif

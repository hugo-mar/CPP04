/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:25:54 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/07/23 16:46:28 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;											// Forward declaration

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}

	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif

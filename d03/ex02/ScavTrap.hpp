/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:44:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:05:15 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap(void);
	ScavTrap& operator=(const ScavTrap& src);

	void	guardGate(void);
	void	attack(const std::string& target);
};

std::ostream&	operator<<(std::ostream& stream, const ScavTrap& scavtrap);

# endif
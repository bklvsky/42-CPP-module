/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:44:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:11:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap: public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& src);
	~FragTrap(void);
	FragTrap& operator=(const FragTrap& src);

	void	highFivesGuys(void);
	void	attack(const std::string& target);
};

std::ostream&	operator<<(std::ostream& stream, const FragTrap& fragtrap);

# endif
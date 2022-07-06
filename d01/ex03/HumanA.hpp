/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:38:22 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 17:20:40 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanA
{

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void) const;

private:
	std::string	name;
	Weapon	&weapon;
};

#endif

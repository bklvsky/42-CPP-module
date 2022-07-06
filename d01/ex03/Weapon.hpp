/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:27:51 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/26 18:51:43 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{

public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType();
	void	setType(std::string type);

private:
	std::string type;
};

#endif

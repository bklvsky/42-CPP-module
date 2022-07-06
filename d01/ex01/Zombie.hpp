/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:39:50 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/14 01:27:21 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{

public:
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	setName(std::string name);

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif

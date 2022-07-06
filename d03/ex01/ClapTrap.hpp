/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:46:43 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 15:59:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class	ClapTrap
{
protected:
	std::string		name;
	int				hitPoints;
	int				initialHitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
	void			setName(std::string name);
	void			setHitPoints(int amount);
	void			setInitHit(int amount);
	void			setEnergyPoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap(void);
	ClapTrap&		operator=(const ClapTrap& src);

	std::string		getName(void) const;
	int				getHitPoints(void) const;
	int				getInitHit(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
	
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& claptrap);

#endif
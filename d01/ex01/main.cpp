/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:31:24 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/14 01:38:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* bobHorde = zombieHorde(5, "Bob");
    
    for (int i = 0; i < 5; i++)
    {
        bobHorde[i].announce();
    }
    delete [] bobHorde;
}

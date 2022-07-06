/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:05:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/04 18:51:25 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& src);
		virtual ~Dog(void);
		Dog& operator=(const Dog& src);
		
		virtual Brain* getBrain(void) const;
		
		virtual void makeSound(void) const;
	private:
		Brain *brain;
};

#endif

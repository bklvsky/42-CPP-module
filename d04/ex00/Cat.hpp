/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:54:03 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/25 10:14:07 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& copy);
		~Cat(void);
		Cat& operator=(const Cat& src);

		virtual void makeSound(void) const;
	private:
};

#endif

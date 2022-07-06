/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:54:03 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/04 18:51:20 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& copy);
		virtual ~Cat(void);
		virtual Cat& operator=(const Cat& src);

		virtual Brain* getBrain(void) const;
		virtual void makeSound(void) const;
	private:
		Brain *brain;
};

#endif

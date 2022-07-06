#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& copy);
		virtual ~Animal(void);
		virtual Animal& operator=(const Animal& src);

		std::string		getType() const;
		virtual void	makeSound(void) const = 0;
		virtual Brain*	getBrain(void) const = 0;

	protected:
		std::string _type;
};

#endif
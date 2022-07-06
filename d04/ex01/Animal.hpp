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
		virtual void	makeSound(void) const;
		virtual Brain*	getBrain(void) const;

	protected:
		std::string _type;
};

#endif
#include "Animal.hpp"

Animal::Animal(void): _type("Just an animal")
{
	std::cout << "Default Constructor called of Animal with a Type " \
	<< this->getType() << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy Constructor called of Animal with a Type " \
	<< copy.getType() << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Destructor called of Animal with a Type " \
	<< this->getType() << std::endl;
}

Animal&	Animal::operator=(const Animal &src)
{
	std::cout << "Assignment operator called for Animal" << std::endl;
	this->_type = src.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

Brain*	Animal::getBrain(void) const
{
	std::cout << "Animal has no brain!" << std::endl;
	return NULL;
}


void	Animal::makeSound(void) const
{
	std::cout << "***animal sounds***" << std::endl;
}

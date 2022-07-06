/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:03:32 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 00:58:49 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	Animal	*animal = new Animal();
	Animal	*cat = new Cat();
	Animal	*dog = new Dog();

	std::cout << std::endl;
	std::cout << "****Normal animals****" << std::endl << std::endl;
	std::cout << animal->getType() << " says ";
	animal->makeSound();
	std::cout << cat->getType() << " says ";
	cat->makeSound();
	std::cout << dog->getType() << " says ";
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "****Destructors****" << std::endl << std::endl;
	delete animal;
	delete cat;
	delete dog;

	std::cout << std::endl;
	std::cout << "****Wrong animals****" << std::endl << std::endl;
	WrongAnimal	*wronganimalcat = new WrongCat();
	WrongCat	*wrongcat = new WrongCat();
	std::cout << wronganimalcat->getType() << " says ";
	wronganimalcat->makeSound();
	std::cout << wrongcat->getType() << " says ";
	wrongcat->makeSound();
	std::cout << std::endl;
	std::cout << "****Destructors****" << std::endl << std::endl;
	delete wronganimalcat;
	delete wrongcat;
}
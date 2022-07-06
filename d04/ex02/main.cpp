/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:03:32 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 01:04:11 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

void	checkDogDeepCopy(Animal* animals[], Dog *originalDog)
{
	std::cout << std::endl << "*** Check deepcopies for dog ***" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Round " << i << std::endl;
		std::cout << "original: " << originalDog->getBrain()->getIdeas()[i] << std::endl;
		std::cout << "copy: " << animals[1]->getBrain()->getIdeas()[i] << std::endl;
		std::cout << std::endl;
	}
}

void	checkCatDeepCopy(Animal* animals[], Cat *originalCat)
{
	std::cout << std::endl << "*** Check deepcopies for cat ***" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Round " << i << std::endl;
		std::cout << "original: " << originalCat->getBrain()->getIdeas()[i] << std::endl;
		std::cout << "copy: " << animals[0]->getBrain()->getIdeas()[i] << std::endl;
		std::cout << std::endl;
	}
}

int	main()
{
	Animal	*animals[6];
	Cat		*catForCopy = new Cat();
	Dog		*dogForCopy = new Dog();
	dogForCopy->getBrain()->setIdea("Squirell", 0);
	catForCopy->getBrain()->setIdea("Fish", 0);
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << i << std::endl;
		if (i % 2 != 0)
		{
			animals[i] = new Dog(*dogForCopy);
			animals[i]->getBrain()->setIdea("Woof", 2);
		}
		else
		{
			animals[i] = new Cat(*catForCopy);
			animals[i]->getBrain()->setIdea("Meow", 2);
		}
		std::cout << std::endl;
	}
	
	checkCatDeepCopy(animals, catForCopy);
	checkDogDeepCopy(animals, dogForCopy);
	std::cout << std::endl;
	std::cout << "*** deleting animals for copies ***" << std::endl;
	std::cout << std::endl;
	delete catForCopy;
	delete dogForCopy;
	std::cout << std::endl;
	std::cout << "*** deleting animals[]***" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Round " << i << std::endl;
		delete animals[i];
	}

	/****************won't compile****************/

	// const Animal* j = new Animal();
	// delete j;
}

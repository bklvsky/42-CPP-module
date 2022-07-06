/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:32:34 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 00:45:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Constructor called of Brain" << std::endl;
	this->setIdeas("idea");
}

Brain::Brain(std::string idea)
{
	std::cout << "Idea Constructor called of Brain" << std::endl;
	this->setIdeas(idea);
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Copy Constructor called of Brain" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Destructor called of Brain" << std::endl;
}

Brain&	Brain::operator=(const Brain &src)
{
	std::cout << "Assignment called of Brain" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}

const std::string*	Brain::getIdeas(void) const
{
	return (this->ideas);
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

void	Brain::setIdea(std::string idea, int i)
{
	if (i < 100)
		this->ideas[i] = idea;
}
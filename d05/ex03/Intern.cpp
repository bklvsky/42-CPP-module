/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:44:25 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:32:16 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::forms[3] =
{
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

Intern::Intern(void)
{
	std::cout << "Default constructor for Intern called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	*this = src;
	std::cout << "Copy constructor for Intern called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Destructor for Intern called" << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Assignment operator for Intern called" << std::endl;
	return (*this);
}

Form*	Intern::makeShrubberyCreationForm(std::string target) const
{
	Form * newForm = new ShrubberyCreationForm(target);
	return (newForm);
}

Form*	Intern::makeRobotomyRequestForm(std::string target) const
{
	Form * newForm = new RobotomyRequestForm(target);
	return (newForm);
}

Form*	Intern::makePresidentialPardonForm(std::string target) const
{
	Form * newForm = new PresidentialPardonForm(target);
	return (newForm);
}

Form*	Intern::makeForm(std::string name, std::string target) const
{
	MakeForms makeForms[] = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (name.compare(Intern::forms[i]) == 0)
		{
			Form* newForm = (this->*makeForms[i])(target);
			return (newForm);
		}
	}
	std::cout << "Intern could not create a form because " << name \
					<< " is not an appropriate name for a form" << std::endl;
	return NULL;
}

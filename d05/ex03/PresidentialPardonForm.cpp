/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:23:20 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/28 20:56:27 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): \
	Form("PresidentialPardonForm", 25, 5), target("target")
{
	std::cout << "Default constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): \
	Form("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "Default constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): \
	Form("PresidentialPardonForm", 25, 5), target(src.getTarget())
{
	std::cout << "Default constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	this->target = src.getTarget();
	this->setSigned(src.getIsSigned());
	std::cout << "Assignment operator for PresidentialPardonForm called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

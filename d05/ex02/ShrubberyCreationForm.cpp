/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:59:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:25:05 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): \
	Form("ShrubberyCreationForm", 145, 137), target("target")
{
	std::cout << "Default constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): \
	Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Default constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): \
	Form("ShrubberyCreationForm", 145, 137), target(src.getTarget())
{
	std::cout << "Default constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	this->target = src.getTarget();
	this->setSigned(src.getIsSigned());
	std::cout << "Assignment operator for ShrubberyCreationForm called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::string targetName = this->target + "_shrubbery";
	std::ofstream target((const char *)&targetName[0]);
	if (target.is_open())
	{
		target << "          &&& &&  & &&" << std::endl;
		target << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		target << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		target << "   &() &\\/&|()|/&\\/ '%' & ()" << std::endl;
		target << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		target << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		target << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		target << "     &&     \\|||" << std::endl;
		target << "             |||" << std::endl;
		target << "             |||" << std::endl;
		target << "             |||" << std::endl;
		target << "       , -=-~  .-^- _" << std::endl;
		target.close();
	}
	else
		std::cout << "Couldn't open " << targetName << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}


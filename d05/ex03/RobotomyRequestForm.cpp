/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:59:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:21:19 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): \
	Form("RobotomyRequestForm", 72, 45), target("target")
{
	std::cout << "Default constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): \
	Form("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Default constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): \
	Form("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
	std::cout << "Default constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	this->target = src.getTarget();
	this->setSigned(src.getIsSigned());
	std::cout << "Assignment operator for RobotomyRequestForm called" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "*****Drilling noises*****" << std::endl;
	int	_rand = rand() % 10;
	if (_rand <= 4)
		std::cout << this->target << " has been robotomized successfully";
	else
		std::cout << "Robotomy on " << this->target << " has failed";
	std::cout << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

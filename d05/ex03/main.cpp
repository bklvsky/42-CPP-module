/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:03:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:32:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>


int main()
{
	Bureaucrat	highAchiever("highAchiever", 1);
	Bureaucrat	lowAchiever("lowAchiever", 150);
	Intern		intern;

	std::cout << std::endl;
	std::cout << "*******Intern makes PresidentialPardonForm*******" << std::endl;
	std::cout << std::endl;
	{
		Form	*internsForm = intern.makeForm("PresidentialPardonForm", "Buba");
		std::cout << *internsForm << std::endl;
		highAchiever.signForm(*internsForm);
		lowAchiever.executeForm(*internsForm);
		highAchiever.executeForm(*internsForm);
		delete internsForm;
	}

	std::cout << std::endl;
	std::cout << "*******Intern makes RobotomyRequestForm*******" << std::endl;
	std::cout << std::endl;
	{
		Form	*internsForm = intern.makeForm("RobotomyRequestForm", "Buba");
		std::cout << *internsForm << std::endl;
		highAchiever.signForm(*internsForm);
		lowAchiever.executeForm(*internsForm);
		highAchiever.executeForm(*internsForm);
		delete internsForm;
	}
	std::cout << std::endl;
	std::cout << "*******Intern makes ShrubberyCreationForm*******" << std::endl;
	std::cout << std::endl;
	{
		Form	*internsForm = intern.makeForm("ShrubberyCreationForm", "Buba");
		std::cout << *internsForm << std::endl;
		highAchiever.signForm(*internsForm);
		lowAchiever.executeForm(*internsForm);
		highAchiever.executeForm(*internsForm);
		delete internsForm;
	}
	std::cout << std::endl;
	std::cout << "*******Intern tries to make a really weird form******" << std::endl;
	std::cout << std::endl;
	intern.makeForm("WeirdForm", "Lol");
	std::cout << std::endl;
	std::cout << "Destructors" << std::endl;
	std::cout << std::endl;

}

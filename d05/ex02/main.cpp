/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:03:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:24:40 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>


void	normPresPardon(void)
{
	Bureaucrat	highAchiever("highAchiever", 1);
	std::cout << highAchiever << std::endl;

	std::cout << std::endl;
	std::cout << "Normal PresidentialPardon Execution" << std::endl;
	std::cout << std::endl;
	{
		Form		*coolForm = new PresidentialPardonForm("boba");
		std::cout << *coolForm << std::endl;
		highAchiever.signForm(*coolForm);
		std::cout << *coolForm << std::endl;
		std::cout << std::endl;
		highAchiever.executeForm(*coolForm);
		std::cout << std::endl;
		delete coolForm;
	}
	std::cout << std::endl;
}

void	normShrubbery(void)
{
	Bureaucrat	highAchiever("highAchiever", 1);
	std::cout << highAchiever << std::endl;

	std::cout << std::endl;std::cout << "Normal ShrubberyCreation Execution" << std::endl;
	std::cout << std::endl;
	{
		Form		*coolForm = new ShrubberyCreationForm("boba");
		std::cout << *coolForm << std::endl;
		highAchiever.signForm(*coolForm);
		std::cout << *coolForm << std::endl;
		std::cout << std::endl;
		highAchiever.executeForm(*coolForm);
		std::cout << std::endl;
		delete coolForm;
	}
	std::cout << std::endl;
}

void	normRobotomy(void)
{
	Bureaucrat	highAchiever("highAchiever", 1);
	std::cout << highAchiever << std::endl;

	std::cout << std::endl;
	std::cout << "Normal RobotomyRequest Execution" << std::endl;
	std::cout << std::endl;
	{
		Form		*coolForm = new RobotomyRequestForm("boba");
		std::cout << *coolForm << std::endl;
		highAchiever.signForm(*coolForm);
		std::cout << *coolForm << std::endl;
		for (int i = 0; i < 9; i++)
		{
			std::cout << std::endl;
			highAchiever.executeForm(*coolForm);
		}
		std::cout << std::endl;
		delete coolForm;
	}
	std::cout << std::endl;
}

void	putUsage(void)
{
	std::cout << "Please enter a number of a test:" << std::endl;
	std::cout << "PresidentialPardonForm: ./a.out 1" << std::endl;
	std::cout << "ShrubberyCreationForm:  ./a.out 2" << std::endl;
	std::cout << "RobotomyRequestForm:    ./a.out 3" << std::endl;
	std::cout << "Exception management:   ./a.out 4" << std::endl;
}

void	checkExcept(void)
{
	Bureaucrat	highAchiever("highAchiever", 1);
	Bureaucrat	lowAchiever("lowAchiever", 150);
	Form	*pres = new PresidentialPardonForm("Buba");

	std::cout << std::endl;
	std::cout << highAchiever << std::endl;
	std::cout << lowAchiever << std::endl;
	std::cout << *pres << std::endl;
	std::cout << std::endl;
	std::cout << "********Trying to execute not signed form********" << std::endl;
	highAchiever.executeForm(*pres);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "****************Signing it****************" << std::endl;
	highAchiever.signForm(*pres);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "********Trying to execute it with low grade********" << std::endl;
	lowAchiever.executeForm(*pres);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "************Finally executing it************" << std::endl;
	highAchiever.executeForm(*pres);
	std::cout << std::endl;
	delete pres;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		putUsage();
		return (0);
	}
	int i = std::atoi(argv[1]);
	switch (i)
	{
	case 1:
		normPresPardon();
		break;
	case 2:
		normShrubbery();
		break;
	case 3:
		normRobotomy();
		break;
	case 4:
		checkExcept();
		break;
	default:
		putUsage();
		break;
	}

	/***************won't compile***************/
	// Form *form = new Form();
	// delete form;
}

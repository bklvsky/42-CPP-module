/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:03:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 00:32:26 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>


int main()
{
	Bureaucrat	highAchiever("highAchiever", 1);
	
	std::cout << highAchiever << std::endl;
	
	std::cout << std::endl;
	{
		Form		coolForm("Cool", 10, 10);
		std::cout << coolForm << std::endl;
		highAchiever.signForm(coolForm);
		std::cout << coolForm << std::endl;
		highAchiever.signForm(coolForm);
		std::cout << coolForm << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat lowAchiever("lowAchiever", 150);
	std::cout << lowAchiever << std::endl;
	
	std::cout << std::endl;
	{
		Form		coolForm("Cool", 10, 10);
		std::cout << coolForm << std::endl;
		lowAchiever.signForm(coolForm);
		std::cout << coolForm << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "Creating not cool form" << std::endl;
		Form notCoolForm("Not Cool", 160, 10);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

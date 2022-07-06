/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:03:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 00:23:25 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>


int main()
{
	Bureaucrat lowAchiever("lowAchiever", 150);
	Bureaucrat highAchiever("highAchiever", 1);
	
	std::cout << highAchiever << std::endl;
	std::cout << lowAchiever << std::endl;
	try
	{
		std::cout << std::endl;
		std::cout << "*****Incrementing highAchiever*****" << std::endl;
		std::cout << std::endl;
		highAchiever.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "*****Normal behaviour*****" << std::endl;
		std::cout << std::endl;
		lowAchiever.incrementGrade();
		std::cout << lowAchiever << std::endl;
		lowAchiever.decrementGrade();
		std::cout << lowAchiever << std::endl;
		std::cout << std::endl;
		std::cout << "*****Decrementing highAchiever*****" << std::endl;
		std::cout << std::endl;
		lowAchiever.decrementGrade();
		std::cout << lowAchiever << std::endl;
		lowAchiever.incrementGrade();
		std::cout << lowAchiever << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "*****Creating really bad bureaucrat (grade 160)*****" << std::endl;
		std::cout << std::endl;
		Bureaucrat fired("fired", 160);
		std::cout << fired << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "*****Creating really good bureaucrat (grade 0)*****" << std::endl;
		std::cout << std::endl;
		Bureaucrat god("fired", 0);
		std::cout << god << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

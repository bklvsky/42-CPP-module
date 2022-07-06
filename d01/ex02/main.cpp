/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:40:57 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/14 01:47:29 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string greeting = std::string("HI THIS IS BRAIN");
	std::string* stringPTR = &greeting;
	std::string& stringREF = greeting;

	std::cout << "Address of the string: " << &greeting << std::endl;
	std::cout << "Address in the pointer: " << stringPTR << std::endl;
	std::cout << "Address of the reference: " << &stringREF << std::endl;

	std::cout << "Value of the string: " << greeting << std::endl;
	std::cout << "Value in the pointer: " << *stringPTR << std::endl;
	std::cout << "Value in the reference: " << stringREF << std::endl;
}

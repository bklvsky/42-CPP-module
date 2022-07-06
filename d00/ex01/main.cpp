/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:31:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/03/29 01:10:38 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void)
{
	std::string command;
	PhoneBook	myPhoneBook;
	
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			myPhoneBook.addContact();
		else if (command == "SEARCH")
			myPhoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "The PhoneBook is closing... Bye!" << std::endl;
			break ;
		}
		else if(command.length() > 0)
		{
			std::cout << command << ": uknown command" << std::endl;
			std::cout << "available commands: [ADD] [SEARCH] [EXIT]" << std::endl;
		}
	}
	return (0);
}
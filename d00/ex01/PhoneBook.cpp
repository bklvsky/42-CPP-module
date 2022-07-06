/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:48:42 by dselmy            #+#    #+#             */
/*   Updated: 2022/03/29 01:15:32 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	PhoneBook::contactsAmount =  0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact()
{
	int contactIndex = this->contactsAmount % 8;
	this->contactsAmount += 1;
	this->contacts[contactIndex].setContact(contactIndex);
	std::cout << "The contact was added succesfully!" << std::endl;
}

void	PhoneBook::displayHeader() const
{
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->contactsAmount && i < 8; i += 1)
	{
		this->contacts[i].displayContactInPhoneBook();
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::searchContacts() const
{
	std::string input;
	int index = 0;
	
	if (this->contactsAmount == 0)
		std::cout << "The PhoneBook is empty, add contacts first" << std::endl;
	else
	{
		PhoneBook::displayHeader();
		std::cout << "Enter contact's index to see full info" << std::endl;
		while (index <= 0 || index > this->contactsAmount || index > 8)
		{
			std::cout << ">>> ";
			std::getline(std::cin, input);
			index = std::atoi(input.c_str());
			if ((index <= 0 || index > this->contactsAmount || index > 8) && input.length() > 0)
				std::cout << "Invalid index" << std::endl;
		}
		this->contacts[index - 1].displayContact();
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:19 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/18 03:51:38 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::fieldsName[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setContact(int index)
{
	int i = Contact::firstName;
	this->index = index;
	while (i <= Contact::darkestSecret)
	{
		std::cout << Contact::fieldsName[i] << ": ";
		std::getline(std::cin, this->fieldValue[i]);
		if (this->fieldValue[i].length() == 0)
			std::cout << "Please, fill in all fields" << std::endl;
		else
			i += 1;
	}
	return;
}

void    Contact::displayContactInPhoneBook() const
{
	std::cout << "|" << std::setw(10) << this->index + 1;
	for (int i = Contact::firstName; i <= Contact::nickName; i += 1)
	{
		std::cout << "|";
		if (this->fieldValue[i].length() < 10)
			std::cout << std::setw(10) << this->fieldValue[i];
		else
			std::cout << this->fieldValue[i].substr(0, 9) << ".";
	}
	std::cout << "|" << std::endl;
	return;
}

size_t	Contact::getMaxWidth() const
{
	size_t maxLen = 0;
	for (int i = Contact::firstName; i <= Contact::darkestSecret; i += 1)
	{
		size_t currentLen = Contact::fieldsName[i].length() + 2 + Contact::fieldValue[i].length();
		if (maxLen < currentLen)
			maxLen = currentLen;
	}
	if (maxLen < 43)
		return (43);
	return (maxLen);
}

void	Contact::displayHorizontalBorder(size_t width) const
{
	std::cout << "|" << std::setw(width + 1) << std::setfill('-') << std::right << "|" << std::endl;
	std::cout << std::setfill(' ');
}

void	Contact::displayContactHeader(size_t width) const
{
	Contact::displayHorizontalBorder(width);
	std::cout << "|" 
			<< std::setw(width / 2 + 4)
			<< std::right
			<< "Contact [" << this->index + 1 << "]";
	std::cout << std::setw(width / 2 - 5 + width % 2) << "|" << std::endl;
	Contact::displayHorizontalBorder(width);
}

void	Contact::displayContact() const
{
	size_t width = Contact::getMaxWidth();
	std::cout << std::endl;
	Contact::displayContactHeader(width);
	for (int i = Contact::firstName; i <= Contact::darkestSecret; i += 1)
	{
		std::cout << "|" << Contact::fieldsName[i] << ": ";
		std::cout << std::setw(width - Contact::fieldsName[i].length() - 2)
				<< std::left << this->fieldValue[i] << "|";
		std::cout << std::endl;
	}
	Contact::displayHorizontalBorder(width);
	std::cout << std::setfill(' ');
	std::cout << std::endl;
	return;
}

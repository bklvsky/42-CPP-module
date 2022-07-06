/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:42:04 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/21 16:32:21 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string inFileName, std::string strToReplace, \
													std::string strReplacement)
{
	this->inFileName = inFileName;
	this->strToReplace = strToReplace;
	this->strReplacement = strReplacement;
	this->outFileName = inFileName + ".replace";
}

Sed::~Sed(void)
{
	if (this->inFile.is_open())
		this->inFile.close();
	if (this->outFile.is_open())
		this->outFile.close();
}

int	Sed::setFile(void)
{
	this->inFile.open((const char *)&this->inFileName[0]);
	if (!this->inFile.is_open() || !this->inFile.good())
	{
		std::cout << this->inFileName << ": cannot open a file" << std::endl;
		return (0);
	}
	std::getline(this->inFile, this->inputContent, '\0');
	if (this->inputContent.length() == 0)
	{
		std::cout << this->inFileName << ": can't be an empty file" \
																<< std::endl;
		return (0);
	}
	this->outFile.open((const char *)&this->outFileName[0]);
	if (!this->outFile.is_open() || !this->outFile.good())
	{
		std::cout << this->outFileName << ": cannot open a file" << std::endl;
		this->inFile.close();
		return (0);
	}
	return (1);
}

size_t	Sed::writeReplacement(size_t startRead, size_t ocurrence)
{
	std::string	lineToWrite = this->inputContent.substr(startRead, \
														ocurrence - startRead);
	this->outFile << lineToWrite << this->strReplacement;
	return lineToWrite.length() + this->strToReplace.length();
}

void	Sed::replace(void)
{
	size_t startRead = 0;
	size_t	ocurrence;
	while ((ocurrence = inputContent.find(this->strToReplace, startRead)) \
														!= std::string::npos)
		startRead += this->writeReplacement(startRead, ocurrence);
	if (startRead != this->inputContent.length())
		this->outFile << this->inputContent.substr(startRead, \
									this->inputContent.length() - startRead);
}

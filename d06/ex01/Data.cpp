/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:10:29 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 23:27:16 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): name("name"), data(0)
{
}

Data::Data(std::string name, int data): name(name), data(data)
{
}

Data::Data(const Data& src): name(src.name), data(src.data)
{
}

Data::~Data(void)
{
}

Data&	Data::operator=(const Data& rhs)
{
	this->name = rhs.name;
	this->data = rhs.data;
	return (*this);
}

bool	Data::operator==(const Data& rhs)
{
	return (this->name == rhs.name && this->data == rhs.data);
}

std::ostream&	operator<<(std::ostream& stream, const Data& rhs)
{
	stream << "name: " << rhs.name << "; data: " << rhs.data;
	return (stream);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:49:14 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 19:41:32 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void): _arg("")
{
	for (int i = 0; i < 4; i++)
		this->_nonConvertible[i] = false;
	this->_specMeaning = false;
	this->_cvalue = 0;
	this->_ivalue = 0;
	this->_fvalue = 0;
	this->_dvalue = 0;
	this->_error = "";
	this->makeLiteral();
}

Converter::Converter(std::string _arg): _arg(_arg)
{
	for (int i = 0; i < 4; i++)
		this->_nonConvertible[i] = false;
	this->_specMeaning = false;
	this->_cvalue = 0;
	this->_ivalue = 0;
	this->_fvalue = 0;
	this->_dvalue = 0;
	this->_error = "";
	this->makeLiteral();
}

Converter::Converter(const Converter& src)
{
	this->_literal = src._literal;
	this->_arg = src._arg;
	this->_specMeaning = src._specMeaning;
	for (int i = 0; i < 4; i++)
		this->_nonConvertible[i] = src._nonConvertible[i];
	this->_cvalue = src._cvalue;
	this->_ivalue = src._ivalue;
	this->_fvalue = src._fvalue;
	this->_dvalue = src._dvalue;
	this->_error = "";
}

Converter::~Converter(void)
{
}

const std::string Converter::getError(void) const
{
	return (this->_error);
}

void	Converter::makeLiteral(void)
{
	if (this->isScpecMeaning())
		this->manageSpecMeaning();
	else if (this->_arg.length() == 1 && !std::isdigit(this->_arg[0]))
		this->_literal = _char;
	else if (this->_arg.find('.') == std::string::npos && this->_arg[this->_arg.length() - 1] != 'f')
		this->_literal = _int;
	else if (this->_arg[this->_arg.length() - 1] == 'f')
		this->_literal = _float;
	else
		this->_literal = _double;
}

bool	Converter::isScpecMeaning(void) const
{
	std::string	kw[10] = {"nanf", "nan", "+inf", "-inf", "+inff", "-inff", "inf", "inff", "-nan", "-nanf"};
	for (int i = 0; i < 10; i++)
	{
		if (this->_arg == kw[i])
			return (true);
	}
	return (false);
}

void	Converter::makeDump(char **dump) const
{
	char	dump_arr[this->_arg.length()];
	for (unsigned i = 0; i < this->_arg.length(); i++)
		dump_arr[i] = 0;
	*dump = dump_arr;
}

bool	Converter::checkLiteral(void)
{
	char	*dump;
	this->makeDump(&dump);
	
	if (this->_literal == _char)
		return (true);
	double value = std::strtod(static_cast<char *>(&this->_arg[0]), &dump);
	if (dump[0])
	{
		if (dump[0] == 'f' && !dump[1])
			return (true);
		this->_error = "wrong formatting";
		return (false);
	}
	if (this->_literal == _int && (value >= INT_MAX || value <= INT_MIN))
	{
		this->_error = "int literal is overflowed";
		return (false);
	}
	return (true);
}

char	Converter::makeCValue(double value)
{
	if (value > CHAR_MAX || value < CHAR_MIN || this->_specMeaning)
	{
		this->_nonConvertible[_char] = true;
		return (0);
	}
	return (static_cast<char>(value));
}

int		Converter::makeIValue(double value)
{
	if (value > INT_MAX || value < INT_MIN || this->_specMeaning)
	{
		this->_nonConvertible[_int] = true;
		return (0);
	}
	return (static_cast<int>(value));
}

void	Converter::makeValues(char value)
{
	this->_cvalue = value;
	this->_ivalue = static_cast<int>(value);
	this->_fvalue = static_cast<float>(value);
	this->_dvalue = static_cast<double>(value);
}

void	Converter::makeValues(int value)
{
	this->_cvalue = this->makeCValue(static_cast<double>(value));
	this->_ivalue = value;
	this->_fvalue = static_cast<float>(value);
	this->_dvalue = static_cast<double>(value);
}

void	Converter::makeValues(float value)
{
	this->_cvalue = this->makeCValue(static_cast<double>(value));
	this->_ivalue = this->makeIValue(static_cast<double>(value));
	this->_fvalue = value;
	this->_dvalue = static_cast<double>(value);
}

void	Converter::makeValues(double value)
{
	this->_cvalue = this->makeCValue(static_cast<double>(value));
	this->_ivalue = this->makeIValue(static_cast<double>(value));
	this->_fvalue = static_cast<float>(value);
	this->_dvalue = value;
}

void	Converter::manageSpecMeaning(void)
{
	std::string	kwFloat[5] = {"nanf", "+inff", "-inff", "inff", "-nanf"};
	std::string	kwDbl[5] = {"nan", "+inf", "-inf", "inf", "-nan"};

	this->_specMeaning = true;
	for (int i = 0; i < 5; i++)
	{
		if (this->_arg == kwFloat[i])
			this->_literal = _float;
		else if (this->_arg == kwDbl[i])
			this->_literal = _double;
		else
			continue;
	}
}

void	Converter::convert(void)
{
	if (this->_literal == _char)
		this->makeValues(this->_arg[0]);
	else if (this->_literal == _int)
		this->makeValues(std::atoi(static_cast<char *>(&this->_arg[0])));
	else if (this->_literal == _float)
		this->makeValues(std::strtod(static_cast<char *>(&this->_arg[0]), NULL));
	else
		this->makeValues(std::strtod(static_cast<char *>(&this->_arg[0]), NULL));
}

void	Converter::putChar(void) const
{
	std::cout << "char: ";
	if (!this->_nonConvertible[_char])
	{
		if (std::isprint(this->_cvalue))
			std::cout << this->_cvalue;
		else
			std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::putInt(void) const
{
	std::cout << "int: ";
	if (!this->_nonConvertible[_int])
		std::cout << this->_ivalue;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::putFloat(void) const
{
	std::cout << "float: ";
	if (!this->_nonConvertible[_float])
	{
		if (this->_fvalue == std::numeric_limits<float>::infinity())
			std::cout << "+";
		std::cout << this->_fvalue;
		if (!this->_specMeaning)
		{
			if (this->_fvalue - static_cast<int>(this->_fvalue) == 0.0)
				std::cout << ".0";
		}
		std::cout << "f";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::putDouble(void) const
{
	std::cout << "double: ";
	if (!this->_nonConvertible[_double])
	{
		if (this->_dvalue == std::numeric_limits<float>::infinity())
			std::cout << "+";
		std::cout << this->_dvalue;
		if (!this->_specMeaning)
		{
			if (this->_dvalue - static_cast<int>(this->_dvalue) == 0.0)
				std::cout << ".0";
		}
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	Converter::putConvertion(void) const
{
	this->putChar();
	this->putInt();
	this->putFloat();
	this->putDouble();
}

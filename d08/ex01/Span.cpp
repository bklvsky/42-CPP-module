/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:36:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/26 16:09:56 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _N(10000), _num(0)
{
}

Span::Span(unsigned int N): _N(N), _num(0)
{
}

Span::Span(const Span & src): _N(src._N), _num(src._num), \
	_shortestSpan(src._shortestSpan), numbers(std::vector<int>(src.numbers))
{
}

Span::~Span(void)
{
}

Span & Span::operator=(const Span & src)
{
	this->_N = src._N;
	this->_num = src._num;
	this->numbers = src.numbers;
	this->_shortestSpan = src._shortestSpan;
	return (*this);
}

unsigned int	Span::getCapacity(void) const
{
	return (this->_N);
}

unsigned int	Span::getSize(void) const
{
	return (this->_num);
}

void	Span::addNumber(int number)
{
	checkOutOfRange(1);
	this->_num += 1;
	if (this->_num == 1)
	{
		this->numbers.push_back(number);
		return;
	}
	if (!std::binary_search(this->numbers.begin(), this->numbers.end(), number))
	{
		std::vector<int>::iterator pos = std::upper_bound(this->numbers.begin(), this->numbers.end(), number);
		if (this->_num == 2)
			this->_shortestSpan = abs(this->numbers[0] - number);
		if (pos != this->numbers.end() && *pos - number < this->_shortestSpan)
			this->_shortestSpan = *pos - number;
		if (pos != this->numbers.begin() && number - *(pos - 1) < this->_shortestSpan)
			this->_shortestSpan = number - *(pos - 1);
		this->numbers.insert(pos, number);
	}
	else
	{
		this->_shortestSpan = 0;
	}
}

int		Span::shortestSpan(void) const
{
	if (this->_num < 2)
		throw (std::logic_error("Not enough numbers to calculate span"));
	return (this->_shortestSpan);
}

int		Span::longestSpan(void) const
{
	if (this->_num < 2)
		throw (std::logic_error("Not enough numbers to calculate span"));
	return (this->numbers.back() - this->numbers.front());
}

std::vector<int> const &Span::getnumbers(void) const
{
	return (this->numbers);
}

void	Span::checkOutOfRange(int toAdd) const
{
	if (toAdd + this->_num > this->_N)
		throw (std::out_of_range("Out of range: impossible to add a number to the Span"));
}

std::ostream&	operator<<(std::ostream & stream, const Span & src)
{
	stream << "Span with capacity of " << src.getCapacity() << ", with " \
	<< src.getSize() << " elements (" << src.getnumbers().size() << \
	" unique elements), longest Span: " << src.longestSpan() \
	<< ", shortest Span: " << src.shortestSpan();
	return (stream);
}

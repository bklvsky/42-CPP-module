/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:03:10 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 03:16:46 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span & src);
		~Span(void);
		Span&	operator=(const Span & src);
		
		void	addNumber(int number);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		
		unsigned int getCapacity(void) const;
		unsigned int getSize(void) const;
		std::vector<int> const &getnumbers(void) const;

		template <typename A>
		void	addNumbers(A begin, A end)
		{
			std::vector<int> range = std::vector<int>(begin, end);
			this->checkOutOfRange(range.size());
			int _num_new = range.size() + this->_num;
			std::sort(range.begin(), range.end());
			std::unique(range.begin(), range.end());
			for (std::vector<int>::iterator it = range.begin(); it != range.end(); it++)
			{
				this->addNumber(*it);
			}
			this->_num = _num_new;
		}

	private:
		unsigned int	_N;
		unsigned int	_num;
		int				_shortestSpan;
		std::vector<int> numbers;

		void	checkOutOfRange(int toAdd) const;
};

std::ostream&	operator<<(std::ostream & stream, const Span & src);

#endif

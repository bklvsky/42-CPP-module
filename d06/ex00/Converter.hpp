/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:03:30 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 22:57:57 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <climits>
# include <limits>

class Converter
{
	private:
		std::string	_arg;
		enum	types
		{
			_char,
			_int,
			_float,
			_double
		};
		int		_literal;
		bool	_specMeaning;
		bool	_nonConvertible[4];
		
		char	_cvalue;
		int		_ivalue;
		float	_fvalue;
		double	_dvalue;
		
		void	makeLiteral(void);
		bool	isScpecMeaning(void) const;
		void	manageSpecMeaning(void);
		void	makeDump(char **dump) const;
		
		void	makeValues(char value);
		void	makeValues(int value);
		void	makeValues(float value);
		void	makeValues(double value);

		char	makeCValue(double value);
		int		makeIValue(double value);
		
		void	putChar(void) const;
		void	putInt(void) const;
		void	putFloat(void) const;
		void	putDouble(void) const;

		std::string _error;
	public:
		Converter(void);
		Converter(std::string arg);
		Converter(const Converter& src);
		~Converter(void);

		bool	checkLiteral(void);
		void	convert(void);
		void	putConvertion(void) const;

		const std::string	getError(void) const;
};

#endif

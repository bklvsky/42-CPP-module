/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:00 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 23:25:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
public:
	std::string	name;
	int			data;

	Data(void);
	Data(std::string name, int data);
	Data(const Data& src);
	~Data(void);
	Data&	operator=(const Data& src);

	bool	operator==(const Data& rhs);
};

std::ostream&	operator<<(std::ostream& stream, const Data& rhs);

#endif

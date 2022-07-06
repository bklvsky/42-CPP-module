/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:41:10 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/17 19:13:28 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
private:
	std::string	inFileName;
	std::string	outFileName;
	std::string	strToReplace;
	std::string	strReplacement;
	std::ifstream	inFile;
	std::ofstream	outFile;

	std::string	inputContent;
	size_t	writeReplacement(size_t startRead, size_t ocurrence);
public:
	Sed(std::string inFileName, std::string strToReplace, \
												std::string strReplacement);
	~Sed();
	int	setFile(void);
	void	replace(void);
};

#endif

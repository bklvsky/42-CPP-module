/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:26:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 00:44:42 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain& copy);
		Brain(std::string idea);
		~Brain();
		Brain& operator=(const Brain& src);

		const std::string* getIdeas(void) const;
		void	setIdeas(std::string idea);
		void	setIdea(std::string idea, int i);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:29:44 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:32:19 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern(void);
		Intern&	operator=(const Intern& src);
		
		Form*	makeForm(std::string name, std::string target) const;
		
	private:
		static const std::string forms[3];

		Form*	makeShrubberyCreationForm(std::string target) const;
		Form*	makeRobotomyRequestForm(std::string target) const;
		Form*	makePresidentialPardonForm(std::string target) const;

		typedef Form* (Intern::*MakeForms)(std::string target) const;
};

#endif

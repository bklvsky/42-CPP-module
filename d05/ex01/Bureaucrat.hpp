/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:49:49 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/28 03:42:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);
		Bureaucrat&	operator=(const Bureaucrat& src);
		
		const std::string	getName(void) const;
		int					getGrade(void) const;		
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form& form) const;


		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private:
		const std::string	name;
		int					grade;
		static const int	lowestGrade = 150;
		static const int	highestGrade = 1;

		void	checkGrade(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& rhs);

#endif

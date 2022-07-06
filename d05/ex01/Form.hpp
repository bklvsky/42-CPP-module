/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:13:46 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 00:25:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string name, const int toSign, const int toExectute);
		Form(const Form& src);
		~Form(void);
		Form&	operator=(const Form& src);
		
		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(const Bureaucrat& bureaucrat); //throws exception

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
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
		static const int	lowestGrade = 150;
		static const int	highestGrade = 1;

		void	checkGrade(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Form& rhs);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:58:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 00:35:21 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name(""), grade(Bureaucrat::lowestGrade)
{
	std::cout << "Default constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), \
														grade(grade)
{
	this->checkGrade();
	std::cout << "Standart constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): name(src.getName()), \
														grade(src.getGrade())
{
	this->checkGrade();
	std::cout << "Copy constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor for " << this->getName() << \
											" Bureaucrat called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	this->grade = src.getGrade();
	std::cout << "Bureaucrat assignment operator: " << \
						"name is constant and hasn't changed" << std::endl;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->grade -= 1;
	this->checkGrade();
}

void	Bureaucrat::decrementGrade(void)
{
	this->grade += 1;
	this->checkGrade();
}

void	Bureaucrat::checkGrade(void) const
{
	if (this->grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		if (form.getIsSigned())
		{
			std::cout << *this << " didn't sign the Form " << form.getName();
			std::cout << " because it is already signed" << std::endl;
			return;
		}
		form.beSigned(*this);
		std::cout << *this << ", signed Form " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << *this << " coulnd't sign Form" << form.getName();
		std::cout << "for a reason:" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This grade is too low!");
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	stream << rhs.getName() << ", bureaucrat, grade " << \
												rhs.getGrade();
	return stream;
}

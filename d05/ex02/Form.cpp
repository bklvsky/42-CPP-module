/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:13:55 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/28 20:56:15 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name(""), isSigned(false), gradeToSign(Form::lowestGrade), \
											gradeToExecute(Form::lowestGrade)
{
	std::cout << "Default constructor for Form called" << std::endl;
}

Form::Form(const std::string name, const int toSign, const int toExecute): \
	name(name), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute)
{
	this->checkGrade();
	std::cout << "Standart constructor for Form called" << std::endl;
}

Form::Form(const Form& src): name(src.getName()), isSigned(false), \
		gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	this->checkGrade();
	std::cout << "Copy constructor for Form called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Destructor for " << this->getName() << \
											" Form called" << std::endl;
}

Form&	Form::operator=(const Form& src)
{
	this->isSigned = src.getIsSigned();
	std::cout << "Form assignment operator: " << \
	"name and grades to execute/sign are constant and haven't changed" << std::endl;
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (this->name);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

void	Form::setSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void	Form::checkGrade(void) const
{
	if (this->gradeToExecute < Form::highestGrade || \
									this->gradeToSign < Form::highestGrade)
		throw Form::GradeTooHighException();
	if (this->gradeToExecute > Form::lowestGrade || \
									this->gradeToSign > Form::lowestGrade)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

void	Form::execute(Bureaucrat const& executor) const
{
	if (!(this->isSigned))
		throw Form::NotSignedFormException();
	if (executor.getGrade() > this->gradeToExecute)
		throw Form::GradeTooLowException();
	this->beExecuted();
}

const char* Form::NotSignedFormException::what() const throw()
{
	return ("The Form is not signed");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("This grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("This grade is too low!");
}

std::ostream& operator<<(std::ostream& stream, const Form& rhs)
{
	stream << "Form " << rhs.getName(); 
	if (rhs.getIsSigned())
		stream << ", signed";
	else
		stream << ", not signed";
	stream << ", grade required to sign: " << rhs.getGradeToSign() << \
	", grade required to execute: " << rhs.getGradeToExecute();
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:13:46 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 01:25:28 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm(void);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	std::string	getTarget(void) const;

	private:
		std::string target;

		virtual void	beExecuted(void) const;
};

#endif

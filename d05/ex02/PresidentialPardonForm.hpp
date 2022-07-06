/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:13:46 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/28 20:56:24 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm(void);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	std::string	getTarget(void) const;

	private:
		std::string target;

		virtual void	beExecuted(void) const;
};

#endif

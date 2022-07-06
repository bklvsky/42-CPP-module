/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:29:27 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 17:04:37 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
private:
	Contact contacts[8];
	int		contactsAmount;
	void	displayHeader() const;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContacts() const;
};

#endif

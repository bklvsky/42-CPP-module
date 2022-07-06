/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:29:25 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 17:03:16 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
private:
	static std::string fieldsName[5];
	enum FieldIndex
	{
		firstName,
		lastName,
		nickName,
		phoneNumber,
		darkestSecret
	};
	std::string fieldValue[5];
	int	index;
	size_t getMaxWidth() const;
	void	displayContactHeader(size_t width) const;
	void	displayHorizontalBorder(size_t width) const;

public:
	Contact();
	~Contact();
	void	setContact(int index);
	void	displayContactInPhoneBook() const;
	void	displayContact() const;
};

#endif

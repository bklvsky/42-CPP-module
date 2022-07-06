/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:14:23 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/24 02:24:09 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
	public:
	
	class RangeException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Index out of range";
			}
	};
	

	Array<T>(void): n(0), elements(NULL) {};
	Array<T>(unsigned int n): n(n)
	{
		if (static_cast<int>(n) < 0)
			throw Array<T>::RangeException();
		T *defaultVal = new T();
		this->elements = new T[n];
		for (unsigned i = 0; i < n; i++)
			this->elements[i] = *defaultVal;
		delete defaultVal;
	}

	Array<T>(const Array<T> & src): n(src.n), elements(new T[src.n])
	{
		for (unsigned int i = 0; i < this->n; i++)
			this->elements[i] = src.elements[i];
	}

	Array<T> &	operator=(const Array<T> & src)
	{
		if (this->n > 0)
			delete [] elements;
		this->n = src.n;
		this->elements = new T[this->n];
		for (unsigned int i = 0; i < this->n; i++)
			this->elements[i] = src.elements[i];
		return (*this);
	}

	~Array<T>(void)
	{
		if (this->n > 0)
			delete [] elements;
	}
	
	T	&operator[](const int index);

	const unsigned&	size(void) const
	{
		return (this->n);
	}
	
	private:
		unsigned int	n;
		T*				elements;

};

template <typename T>
T	& Array<T>::operator[](const int index)
{
	if (index >= static_cast<int>(this->n) || index < 0)
		throw Array<T>::RangeException();
	return (this->elements[index]);
}

#endif

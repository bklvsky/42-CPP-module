/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 04:01:07 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 02:44:10 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack<T>(void){};
		MutantStack<T>(const MutantStack<T> & src){};
		~MutantStack<T>(void){};
		MutantStack<T> & operator=(const MutantStack<T> & src){return *this;}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		
		iterator begin(void)
		{
			return (this->c.begin());
		}
		
		iterator end(void)
		{
			return (this->c.end());
		}

		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}
};

#endif

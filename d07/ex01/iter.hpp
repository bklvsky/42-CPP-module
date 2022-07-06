/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 02:58:44 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/24 01:38:52 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* array, int size, void(*f)(T const & ))
{
	for (int i = 0; i < size; i++)
		(*f)(array[i]);
}

#endif

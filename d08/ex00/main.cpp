/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 03:09:45 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/26 16:48:42 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int>vctr;
	for (int i = 0; i < 10; i++)
		vctr.push_back(i);
	std::vector<int>::iterator iter = ::easyfind(vctr, 4);
	std::cout << "vector from the number 4" << std::endl; 
	while (iter != vctr.end())
	{
		std::cout << "vector:" << *iter << std::endl;
		iter++;
	}
	std::cout << std::endl;
	std::list<int>lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	std::list<int>::iterator iterr = ::easyfind(lst, 6);
	std::cout << "list from the number 6" << std::endl; 
	while (iterr != lst.end())
	{
		std::cout << "list: " << *iterr << std::endl;
		iterr++;
	}	
}

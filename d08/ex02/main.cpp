/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 04:00:12 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/26 16:54:20 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <cstdlib>

void    test_reverse_iterator(MutantStack<int> & mstack, std::list<int> & lst)
{	
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	std::list<int>::reverse_iterator lit = lst.rbegin();
	std::list<int>::reverse_iterator lite = lst.rend();
	std::cout << "****testing reverse iterators****" << std::endl;
	std::cout << std::endl << "Put all the stack in reverse order" << std::endl;
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	std::cout << std::endl << "Put all the list in reverse order" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit;
		++lit;
		if (lit == lite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}

void    test_iterator(MutantStack<int> & mstack, std::list<int> & lst)
{	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	std::cout << "****testing regular iterators****" << std::endl;
	std::cout << std::endl << "Put all the stack" << std::endl;
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	std::cout << std::endl << "Put all the list" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit;
		++lit;
		if (lit == lite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}

void    test_conversion_into_std_stack(MutantStack<int> & mstack)
{
	std::stack<int> stdstack(mstack);
	std::cout<< "****testing conversion into std::stack****" << std::endl;
	std::cout << std::endl;
	while(!stdstack.empty())
	{
		std::cout << std::endl;
		std::cout << "std::stack   " << stdstack.top() << std::endl;
		std::cout << "mutant stack " << mstack.top() << std::endl;
		stdstack.pop();
		mstack.pop();
	}
}

void    test_subj(void)
{
	MutantStack<int>    mstack;
	std::list<int>      lst;
	
	mstack.push(5);
	mstack.push(17);
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "At the top of the stack: " << mstack.top() << " list: " << lst.back() << std::endl;
	mstack.pop();
	lst.pop_back();
	std::cout << "Size of the stack: " << mstack.size() << " list: " << lst.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << std::endl;
	test_iterator(mstack, lst);
}

void	init(MutantStack<int> & mstack, std::list<int> & lst)
{
	for (int i = 0; i < 10; i++)
	{
		lst.push_back(i);
		mstack.push(i);
	}
}

void	test_stack_funcionality(void)
{
	std::cout << "****testing basic MutantStack functionality****" << std::endl;
	std::cout << std::endl;
	MutantStack<int> mstack;
	std::cout << std::boolalpha << "At the creation mstack is empty: " << mstack.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "Adding numbers (0...5) to mstack" << std::endl;
	std::cout << "Mstack: ";
	for (int i = 0; i < 6; i++)
	{
		mstack.push(i);
		std::cout << mstack.top();
		if (i == 5)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << "At the end mstack:" << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "next element: " << mstack.top() << std::endl;
}

void	putUsage(void)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "      ./mutant 1 - test for basic stack functionality" << std::endl;
	std::cout << "      ./mutant 2 - test for iterators" << std::endl;
	std::cout << "      ./mutant 3 - test for reverse iterators" << std::endl;
	std::cout << "      ./mutant 4 - test for conversion into std::stack" << std::endl;
	std::cout << "      ./mutant 5 - basic test from subject" << std::endl;
}

int main(int argc, char **argv)
{
	MutantStack<int>    mstack;
	std::list<int>      lst;

	init(mstack, lst);
	if (argc != 2)
	{
		putUsage();
		return 0;
	}

	int i = std::atoi(argv[1]);
	switch(i)
	{
		case 1:
			test_stack_funcionality();
			break;
		case 2:
			test_iterator(mstack, lst);
			break;
		case 3:
			test_reverse_iterator(mstack, lst);
			break;
		case 4:
			test_conversion_into_std_stack(mstack);
			break;
		case 5:
			test_subj();
			break;
		default:
			putUsage();
			break;
	}
	return 0;
}

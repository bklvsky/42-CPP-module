/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 05:11:09 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/26 17:04:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <list>
#include <ctime>
#include <iostream>

#define MAX_NUM 100000

void	testFromSubject(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	return ;
}

void	testExceptions(void)
{
	Span span = Span(10);

	try
	{
		std::cout << "***trying to get longestSpan from empty span***" << std::endl;
		span.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		span.addNumber(i);

	try
	{
		std::cout << "***trying to add number to a full span***" << std::endl;
		span.addNumber(100);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;		
	}
	std::cout << std::endl;
	
	Span span2 = Span(10);
	std::vector<int> v(10, 2);
	for (int i = 0; i < 5; i++)
	{
		span2.addNumber(i);
	}
	try
	{
		std::cout << "***trying to add vector of 10 to a span with 5 numbers left***" << std::endl;
		span2.addNumbers(v.begin(), v.end());
	}
	catch (std::exception& e)
	{
		std::cout << "Caught an exception" << std::endl;
		std::cout << e.what() << std::endl;		
	}
}

/*spans of 10 and 100 thousands elements work instantly; of a million works slowly*/

void	testAddNumbersFromIterators(void)
{
	Span	span = Span(MAX_NUM);
	std::list<int> lst;
	std::list<int> lst2;
	std::vector<int> vect(MAX_NUM / 4);
	std::vector<int> vect2(MAX_NUM / 4);

	std::srand(std::time(NULL) % 100);
	for (int i = 0; i < MAX_NUM / 4; i++)
	{
		lst.push_back(std::rand());
		lst2.push_back(std::rand());
		vect[i] = std::rand();
		vect2[i] = std::rand();
	}
	std::cout << "***adding a list of " << lst.size() << " elements to the span***" << std::endl;
	span.addNumbers(lst.begin(), lst.end());
	std::cout << "***adding a list of " << lst2.size() << " elements to the span***" << std::endl;
	span.addNumbers(lst2.begin(), lst2.end());
	std::cout << "***adding a vector of " << vect.size() << " elements to the span***" << std::endl;
	span.addNumbers(vect.begin(), vect.end());
	std::cout << "***adding a vector of " << vect2.size() << " elements to the span***" << std::endl;
	span.addNumbers(vect2.begin(), vect2.end());
	std::cout << std::endl;
	std::cout << span << std::endl;
	std::cout << std::endl;
	std::cout << "biggest num = " << span.getnumbers().back() << std::endl;
	std::cout << "smallest num = " << span.getnumbers().front() << std::endl;
}

void	basicTest(void)
{
	Span	span = Span(26);
	std::vector<int> vct;
	
	std::srand(std::time(NULL) % 100);
	for (int i = 0; i < 25; i++)
	{
		int toAdd= rand() % 1000;
		toAdd += toAdd % 2;
		vct.push_back(toAdd);
	}
	span.addNumbers(vct.begin(), vct.end());
	std::sort(vct.begin(), vct.end());
	std::vector<int> numbers(span.getnumbers());
	std::cout << "******std::vector vct with even numbers is added to the span******" << std::endl;
	std::cout << std::endl;
	std::cout << "vct: "  << std::endl;
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "numbers stored in span: "  << std::endl;
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << span << std::endl;
}

void	putUsage(void)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "      ./span 1 - basic test from subject" << std::endl;
	std::cout << "      ./span 2 - test for addNumbers from iterators with great capacity" << std::endl;
	std::cout << "      ./span 3 - basic test with visualizing the numbers in span" << std::endl;
	std::cout << "      ./span 4 - test for exceptions" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		putUsage();
		return (0);
	}
	int i = std::atoi(argv[1]);
	switch (i)
	{
	case 1:
		testFromSubject();
		break;
	case 2:
		testAddNumbersFromIterators();
		break;
	case 3:
		basicTest();
		break;
	case 4:
		testExceptions();
		break;
	default:
		putUsage();
		break;
	}
}

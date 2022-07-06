/* ************************************************************************************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:32:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/24 20:03:31 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

class Awesome
{
	public:
		Awesome(void): _n(42) {}
		int get() const {return this->_n;}
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome & a) { o << a.get(); return o;}

int main(void)
{
	
	Array<int> arr (10);

	arr[1] = 1;
	arr[2] = 2;
	std::cout << "arr[0] (default) = " << arr[0] << " arr[1] = " \
							<< arr[1] << " arr[2] = "<< arr[2] << std::endl;
	std::cout << "size: " << arr.size() << std::endl;
	try
	{
		std::cout << std::endl;
		std::cout << "*******Accessing element with index = 12*******" << std::endl;
		std::cout << arr[12] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "*******Accessing element with index = -10*******" << std::endl;
		std::cout << arr[-10] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "*******Trying to create an Array(-10)*******" << std::endl;
		Array<int> arr2 (-10);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught an exception: " << e.what() << '\n';
	}

	Array<std::string> strarr = Array<std::string>();
	std::cout << std::endl;
	std::cout << "*******Creating an empty array*******" << std::endl;
	std::cout << "size: " << strarr.size() << std::endl;
	try
	{
		std::cout << "*******Trying to access its element*******" << std::endl;
		std::cout << strarr[1] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}

	
	{
		std::cout << std::endl;
		std::cout << "******Check assignment operator for deepcopy******" << std::endl;
		Array<int> intarr(5);
		intarr[0] = 10;
		intarr[1] = 11;
		intarr[2] = 12;
		std::cout << "intarr[0] = " << intarr[0] << " intarr[1] = " \
								<< intarr[1] << " intarr[2] = "<< intarr[2] << std::endl;
		intarr = arr;
		std::cout << "intarr = arr" << std::endl;
		std::cout << "intarr[0] = " << intarr[0] << " intarr[1] = " \
								<< intarr[1] << " intarr[2] = "<< intarr[2] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Original Array after deleting the copy" << std::endl;
	std::cout << "arr[0] (default) = " << arr[0] << " arr[1] = " \
							<< arr[1] << " arr[2] = "<< arr[2] << std::endl;
	std::cout << std::endl;
	std::cout << "******Array with complex types******" << std::endl;
	Array<Awesome> awesome (3);
	std::cout << "awesome[0] = " << awesome[0] << " awesome[1] = " << awesome[1] << " awesome[2] = " << awesome[2] << std::endl;
}

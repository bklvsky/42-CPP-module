/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:15:30 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 23:27:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data	*data = new Data("name", 42);
	uintptr_t	raw = serialize(data);
	
	Data	*dataFromRaw = deserialize(raw);
	std::cout << "Original Data: " << *data << std::endl;
	std::cout << "Data from Raw: " << *dataFromRaw << std::endl;
	std::cout << "Original Data == Data from Raw is " \
								<< (*dataFromRaw == *data) << std::endl;
}

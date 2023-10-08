/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:03:06 by mbouaza           #+#    #+#             */
/*   Updated: 2023/09/18 13:30:37 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data * ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data *ptr = new Data;
	Data *newptr;
	
	ptr->test = 50;
	ptr->test2 = 'c';

	std::cout << "Data befor serialize test = " << ptr->test << std::endl;
	std::cout << "Data befor serialize test2 = " << ptr->test2 << std::endl;

	std::cout << std::endl;

	newptr = deserialize( serialize(ptr) );
	
	std::cout << "Data after serialize test = " << deserialize( serialize(ptr) )->test << std::endl;
	std::cout << "Data after serialize test2 = " << deserialize( serialize(ptr) )->test2 << std::endl;

	std::cout << std::endl;
	
	std::cout << "Data (newptr) after serialize test = " << newptr->test << std::endl;
	std::cout << "Data (newptr) after serialize test2 = " << newptr->test2 << std::endl;

	delete ptr;
}
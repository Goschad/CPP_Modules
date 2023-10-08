/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:33:44 by mbouaza           #+#    #+#             */
/*   Updated: 2023/10/05 17:47:18 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void func1(std::string &temptype)
{
	temptype.append("_func");
}

void func2(int &temptype)
{
	temptype = temptype * -1;
}

void func3(int &temptype)
{
	if (temptype % 2 == 0)
		std::cout << "in the table of 2 : " << temptype << std::endl;
}

void func4(std::string &temptype)
{
	std::cout << "size of word is : " << temptype.length() << std::endl;
}

int main( void )
{
	// test 1 //

	std::cout << "--------------- test 1 ---------------"<< std::endl;

	std::cout << std::endl;

	std::string tabofstr[5] = {"moi", "poids", "doigt", "caca", "toi"};
	unsigned int size = 5;

	for (unsigned int i = 0; i < size; i++)
		std::cout << "old word = " << tabofstr[i] << std::endl;

	::iter(tabofstr, size, &func1);

	std::cout << std::endl;

	for (unsigned int i = 0; i < size; i++)
		std::cout << "new word = " << tabofstr[i] << std::endl;
	
	std::cout << std::endl;

	// test 2 //

	std::cout << "--------------- test 2 ---------------"<< std::endl;

	std::cout << std::endl;

	int tabofint[5] = {50, 0, -10, 8048, -900};

	for (unsigned int i = 0; i < size; i++)
		std::cout << "old value = " << tabofint[i] << std::endl;

	std::cout << std::endl;

	::iter(tabofint, size, &func2);

	for (unsigned int i = 0; i < size; i++)
		std::cout << "new value = " << tabofint[i] << std::endl;

	std::cout << std::endl;

	// test 3 //

	std::cout << "--------------- test 3 ---------------"<< std::endl;

	std::cout << std::endl;

	int tabint[5] = {2, 1, 555, 3000000, 57};

	::iter(tabint, size, &func3);

	std::cout << std::endl;

	// test 4 //

	std::cout << "--------------- test 4 ---------------"<< std::endl;

	std::cout << std::endl;

	std::string tabend[5] =  {"coucou", "n", "jojojojojojojojojojojojo", "jesuisla", "78"};

	::iter(tabend, size, &func4);
}
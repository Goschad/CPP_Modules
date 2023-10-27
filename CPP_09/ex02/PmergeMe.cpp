/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:36 by mbouaza           #+#    #+#             */
/*   Updated: 2023/10/27 19:35:25 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void err(std::string str)
{
	std::cerr << str << std::endl;
}

static void swapV(std::vector< int > *container, int a, int b)
{
	int p_a;
	int p_b;
	int i = 0;
	std::vector< int > swaped;
	std::vector< int >::iterator it;

	for (it = container->begin(); it != container->end(); ++it)
	{
		if (i == a)
			p_a = *it;
		if (i == b)
			p_b = *it;
		i++;
	}

	i = 0;

	for (it = container->begin(); it != container->end(); ++it)
	{
		if (i == a && p_a > p_b)
			swaped.push_back(p_b);
		else if (i == b && p_a > p_b)
			swaped.push_back(p_a);
		else
			swaped.push_back(*it);
		i++;
	}

	container->clear();

	for (it = swaped.begin(); it != swaped.end(); ++it)
		container->push_back(*it);
}

// change

static void swapD(std::deque< int > *container, int a, int b)
{
	int p_a;
	int p_b;
	int i = 0;
	std::deque< int > swaped;
	std::deque< int >::iterator it;

	for (it = container->begin(); it != container->end(); ++it)
	{
		if (i == a)
			p_a = *it;
		if (i == b)
			p_b = *it;
		i++;
	}

	i = 0;

	for (it = container->begin(); it != container->end(); ++it)
	{
		if (i == a && p_a > p_b)
			swaped.push_back(p_b);
		else if (i == b && p_a > p_b)
			swaped.push_back(p_a);
		else
			swaped.push_back(*it);
		i++;
	}

	container->clear();

	for (it = swaped.begin(); it != swaped.end(); ++it)
		container->push_back(*it);
}

static bool VerifSortV( std::vector< int > container )
{
	bool t = false;
	int n;
	std::vector< int >::iterator it;

	if (container.size() == 1)
		return (true);
	for (it = container.begin(); it != container.end(); ++it)
	{
		if (t == false)
		{
			n = *it;
			t = true;
		}
		if (n <= *it)
			n = *it;
		else
			return (false);
	}
	return (true);
}

static bool VerifSortD( std::deque< int > container )
{
	bool t = false;
	int n = 0;
	std::deque< int >::iterator it;

	if (container.size() == 1)
		return (true);
	for (it = container.begin(); it != container.end(); ++it)
	{
		if (t == false)
		{
			n = *it;
			t = true;
		}
		if (n <= *it)
			n = *it;
		else
			return (false);
	}
	return (true);
}

static int return_posV( std::vector< int > v , int pos)
{
	int i = 0;
	std::vector< int >::iterator vI;

	for (vI = v.begin(); vI != v.end(); ++vI)
	{
		if (i == pos)
			return (*vI);
		i++;
	}
	return (0);
}

static int return_posD( std::deque< int > v , int pos)
{
	int i = 0;
	std::deque< int >::iterator vI;

	for (vI = v.begin(); vI != v.end(); ++vI)
	{
		if (i == pos)
			return (*vI);
		i++;
	}
	return (0);
}

int all_check(int argc, char **argv)
{
	if (argc < 2)
		return (err("Error"), -1);
	for (int j = 1; argv[j]; j++)
	{
		for (int i = 0; argv[j][i]; i++)
			if ((argv[j][i] < '0' || argv[j][i] > '9'))
				return (err("Error"), -1);
		if (std::atoi(argv[j]) > 2147483647)
			return (err("Error"), -1);
	}

	std::cout << "Before: ";
	for (int j = 1; argv[j]; j++)
	{
		std::cout << argv[j] << " ";
	}
	std::cout << std::endl;
	return (1);
}

void fill_list( std::vector< int > *list_v, std::deque< int > *list_d, char **argv )
{
	for (int i = 1; argv[i] ;i++)
	{
		list_d->push_back(std::atoi(argv[i]));
		list_v->push_back(std::atoi(argv[i]));
	}
}

void SortForV( std::vector< int > v )
{
	int pair = 2;
	int j = 0;
	int i = 0;
	clock_t t ;
	std::vector< int >::iterator it;

	t = clock();
	while (!VerifSortV( v ))
	{
		for (it = v.begin(); it != v.end(); ++it)
		{
			if (j < (pair - 1))
				break;
			if (i + 1 < v.size())
				swapV(&v, i, i + 1);
			j++;
			i += 1;
		}
		j = 0;
		i = 0;
		pair = pair * 2;
	}
	
	std::cout << "After:";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << (double)((clock() - t) / (double)(CLOCKS_PER_SEC / 1000)) << " us" << std::endl;
}

void SortForD( std::deque< int > d )
{
	int pair = 2;
	int j = 0;
	int i = 0;
	clock_t t ;
	std::deque< int >::iterator it;

	t = clock();
	while (!VerifSortD( d ))
	{
		for (it = d.begin(); it != d.end(); ++it)
		{
			if (j < (pair - 1))
				break;
			if (i + 1 < d.size())
				swapD(&d, i, i + 1);
			j++;
			i += 1;
		}
		j = 0;
		i = 0;
		pair = pair * 2;
	}
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << (double)((clock() - t) / (double)(CLOCKS_PER_SEC / 1000)) << " us" << std::endl;
}
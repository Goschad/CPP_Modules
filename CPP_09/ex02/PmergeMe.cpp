/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GIGI <GIGI@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:36 by mbouaza           #+#    #+#             */
/*   Updated: 2023/10/31 03:07:02 by GIGI             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void err(std::string str)
{
	std::cerr << str << std::endl;
}

static void displayDeque(std::deque< int > container)
{
    std::deque< int >::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

static void displayVector(std::vector< int > container)
{
    std::vector< int >::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

static void mergeInsertSortDeque(std::deque< int > *d)
{
	int temp;
	std::deque< int >::iterator it1, it2;

    for (it1 = d->begin() + 1; it1 != d->end(); ++it1)
    {
        temp = *it1;
        it2 = it1;
        while (it2 != d->begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

static void mergeInsertSortVector(std::vector< int > *v)
{
	int temp;
	std::vector<int>::iterator it1, it2;

    for (it1 = v->begin() + 1; it1 != v->end(); ++it1)
    {
        temp = *it1;
        it2 = it1;
        while (it2 != v->begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

int allCheck(int argc, char **argv)
{
	if (argc < 2)
		return (err("Error"), -1);
	for (int j = 1; argv[j]; j++)
	{
		for (int i = 0; argv[j][i]; i++)
			if ((argv[j][i] < '0' || argv[j][i] > '9'))
				return (err("Error"), -1);
		if (std::atoi(argv[j]) > 2147483647 || std::atoi(argv[j]) < 0)
			return (err("Error"), -1);
	}
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

void adventureTime( std::vector< int > *list_v, std::deque< int > *list_d )
{
	clock_t t, end;
	double time1, time2;

	std::cout << "Before: ";
    displayDeque(*list_d);

	t = clock();
    mergeInsertSortDeque(list_d);
	end = clock();
    time1 = static_cast<double>(end - t) / CLOCKS_PER_SEC * 1000;

	t = clock();
    mergeInsertSortVector(list_v);
	end = clock();
    time2 = static_cast<double>(end - t) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	displayVector(*list_v);

	std::cout << "Time to process a range of " << list_d->size() << " elements with std::deque< int >: " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << list_v->size() << " elements with std::vector< int >: " << time2 << " us" << std::endl;
}
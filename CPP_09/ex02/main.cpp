/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:57 by mbouaza           #+#    #+#             */
/*   Updated: 2023/10/27 19:30:42 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector< int > list_v;
	std::deque< int > list_d;
	if (all_check(argc, argv) == -1) // a check
		return (-1);
	fill_list( &list_v, &list_d, argv);
	SortForV( list_v );
	SortForD( list_d );
	return (0);
}
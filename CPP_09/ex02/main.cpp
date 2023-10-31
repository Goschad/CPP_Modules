/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: GIGI <GIGI@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:57 by mbouaza           #+#    #+#             */
/*   Updated: 2023/10/31 03:04:40 by GIGI             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector< int > list_v;
	std::deque< int > list_d;
	
	if (allCheck(argc, argv) == -1)
		return (-1);
	fill_list( &list_v, &list_d, argv);
	adventureTime( &list_v, &list_d );
	return (0);
}
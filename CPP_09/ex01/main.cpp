/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:56:27 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/08 22:03:11 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN Rpn;

	if (Rpn.init_all(argc, argv))
		return (-1);
	if (Rpn.PolishMath(argv, -1))
		return (-1);
	return (0);
}
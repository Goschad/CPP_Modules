#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int     allCheck(int argc, char **argv);
void    fill_list( std::vector< int > *list_v, std::deque< int > *list_d, char **argv );

// Sort //

void    adventureTime( std::vector< int > *list_v, std::deque< int > *list_d );

#endif
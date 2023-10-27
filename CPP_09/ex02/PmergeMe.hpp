#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <time.h>

void fill_list( std::vector< int > *list_v, std::deque< int > *list_d, char **argv );
int all_check(int argc, char **argv);

// Sort //

void SortForV( std::vector< int > v );
void SortForD( std::deque< int > d );

#endif
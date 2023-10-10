#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// include

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <time.h>

/* --- error macro --- */

#define E_PARAM "Error: could not open file."
#define E_BTC(program) ("Error: Wrong program name (" + program + ").")
#define E_FILE(file) ("Error: " + file + " doesn't exist / can't be opened or is empty.")
#define E_NEG "Error: not a positive number."
#define E_INPUT(date) ("Error: bad input => " + date)
#define E_INPUT_HIGHT_DATE(date) ("Error: input exceeds current date => " + date)
#define E_INPUT_LOW_DATE(date) ("Error: input is a date too small date => " + date)
#define E_INT_MAX "Error: too large a number."
#define E_DATE(date) ("Error: unknow date => " + date)
#define E_RATE "Error: unknow rate"
#define E_NEG_RATE "Error: not a positive rate."

/* --- functions --- */

// void

void err(std::string str);
void print(std::string str);
void analyseData(std::list<std::string> data, std::list<std::string> input);

bool SimpleVerif(int argc, char **argv);

// string

std::string gnl(std::string file);

// list

std::list<std::string> split(std::string s, std::string c);

#endif
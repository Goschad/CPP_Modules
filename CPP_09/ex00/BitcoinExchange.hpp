#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// include

#include <iostream>
#include <fstream>
#include <string>
#include <list>

// macro

#define RPL(date, value, rate) (date + " => " + value + " = " + rate)

// error macro

#define E_PARAM "Error: could not open file."
#define E_BTC(program) ("Error: Wrong program name (" + program + ").")
#define E_FILE(file) ("Error: " + file + " doesn't exist / can't be opened.")
#define E_NEG "Error: not a positive number."
#define E_INPUT(date) ("Error: bad input => " + date)
#define E_INPUT_HIGHT_DATE(date) ("Error: input exceeds current date => " + date)
#define E_INPUT_LOW_DATE(date) ("Error: input is a date too small date => " + date)
#define E_INT_MAX "Error: too large a number."
#define E_DATE(date) ("Error: unknow date => " + date)
#define E_RATE "Error: unknow rate"
#define E_NEG_RATE "Error: not a positive rate."

#endif
#include "BitcoinExchange.hpp"

// write error on error output

void err(std::string str)
{
	std::cerr << str << std::endl;
}

// write with std::cout

void print(std::string str)
{
	std::cout << str << std::endl;
}


// return a list of character strings obtained by separating the 's' from using string 'c'.

std::list<std::string> split(std::string s, std::string c)
{
    std::list<std::string>    splitted;
    int last_space = 0;
    size_t space = s.find(c, 0);

    while (space != std::string::npos) 
	{
        splitted.push_back(s.substr(last_space, space - last_space));
        last_space = space + 1;
        space = s.find(c, space + 1);
    }
    splitted.push_back(s.substr(last_space, s.size()));
    return (splitted);
}

// checks for any potential errors when launching the program

static bool verification(std::string file)
{
	std::ifstream ifs(file);

	char *line = new char [1];

	if (!ifs.good() || ifs.fail() || ifs.bad() || !ifs.is_open() || !ifs.read(line, 1))
	{
		delete [] line;
		ifs.close();
		return (err(E_FILE(file)), false);
	}
	delete [] line;
	ifs.close();
	return (true);
}

bool SimpleVerif(int argc, char **argv)
{
	std::string program = argv[0];

	if (program != "./btc")
		return (err(E_BTC(program)), false);
	else if (argc != 2)
		return (err(E_PARAM), false);
	else if (!verification(argv[1]) || !verification("data.csv"))
		return (false);
	return (true);
}

// get_next_line in cpp after verification by 'SimpleVerif()'

std::string gnl(std::string file)
{
	int length = 0;
	char *buffer = NULL;
	std::string newFile;
	std::ifstream ifs(file, std::ifstream::binary);
	
	ifs.seekg (0, ifs.end);
	length = ifs.tellg();
	ifs.seekg (0, ifs.beg);

	buffer = new char [length];
	ifs.read (buffer, length);
	newFile = buffer;
	delete [] buffer;

	ifs.close();
	return (newFile);
}

// find rate of data.csv and value of input (ez)

static bool verifPos(std::string input)
{
	int value = 0;
	std::list<std::string> list = split(input, " ");
	std::list<std::string>::iterator it = list.begin();

	++it;
	++it;
	value = std::atof((*it).c_str());
	if (value < 0)
		return (false);
	return (true);
}

static bool verifMax(std::string input)
{
	long value = 0;
	std::list<std::string> list = split(input, " ");
	std::list<std::string>::iterator it = list.begin();

	++it;
	++it;
	value = std::atol((*it).c_str());																					
	if (value > 2147483647 || value > 1000)
		return (false);
	return (true);
}

static int verifValue(std::string input)
{
	char c = 0;
	int point = 0;

	for (int i = 0; input.c_str()[i]; i++)
	{
		c = input.c_str()[i];
		if (c == '.')
			point++;
		else if ((c < '0' && c > '9') || input.c_str()[0] == '.')
			return (err(E_INPUT(input)) ,-1);
	}
	if (point == 0)
		return (1);
	else if (point == 1)
		return (2);
	
	return (err(E_INPUT(input)) ,-1);
}

static bool emptyInput(std::string input)
{
	char c = 0;

	if (!input.c_str()[1])
			return (true);
	for (int i = 0; input.c_str()[i]; i++)
	{
		c = input.c_str()[i];
		if (c != ' ' && c != '\n' && c != '\t')
			break;
		else if (!input.c_str()[i + 1])
			return (true);
	}
	return (false);
}

static std::string giveInputInfo(std::string input, int n)
{
	int i = 1;
	std::list<std::string> list = split(input, " ");
	std::list<std::string>::iterator it;
	std::list<int> listInt;

	for (it = list.begin(); it != list.end(); ++it)
	{
		listInt.push_back(i);
		if (std::find(listInt.begin(), listInt.end(), n) != listInt.end())
		{
			listInt.clear();
			return (*it);
		}
		listInt.clear();
		i++;
	}
	return ((*it));
}

// 31 et 30 janvier 31

static bool verifTime(int year, int month, int day, std::string date)
{
	time_t timestamp = time( NULL );
	struct tm *timeptr = localtime( & timestamp );;

	int t_year = 1900 + timeptr->tm_year;
	int t_month = timeptr->tm_mon + 1;
	int t_day = timeptr->tm_mday;

	if (year <= 2009 && month <= 1 && day <= 1)
		return (err(E_INPUT_LOW_DATE(date)), false);
	else if (!(month >= 1 && month <= 12))
		return (err(E_INPUT(date)), false);
	else
	{
		if (month == 2 && year % 4 == 0 && (day < 1 || day > 29))
			return (err(E_INPUT(date)), false);
		else if (month == 2 && (day < 1 || day > 28) )
			return (err(E_INPUT(date)), false);
		else if (month % 2 == 0 && day > 30)
			return (err(E_INPUT(date)), false);
		else if (month % 2 != 0 && day > 31)
			return (err(E_INPUT(date)), false);
	}
	if (year > t_year)
		return (err(E_INPUT_HIGHT_DATE(date)), false);
	else if (year == t_year && month > t_month)
		return (err(E_INPUT_HIGHT_DATE(date)), false);
	else if (year == t_year && month == t_month && day > t_day)
		return (err(E_INPUT_HIGHT_DATE(date)), false);
	return (true);
}

static bool verifHyphen(std::string date)
{
	std::string value;
	char c = 0;
	int n = 0;

	for (int i = 0; date.c_str()[i]; i++)
	{
		c = date.c_str()[i];
		if (c == '-')
			n++;
	}

	if (!verifMax(date))
		return (err(E_INT_MAX), false);

	if (n != 2)
	{
		if (n > 2 && !verifPos(date))
			return (err(E_NEG), false);
		return (err(E_INPUT(date)), false);
	}

	for (int i = 0; date.c_str()[i]; i++)
	{
		c = date.c_str()[i];
		if (c != '-' && (c < '0' && c > '9'))
			return (err(E_INPUT(date)), false);
	}

	std::list<std::string> input = split(date, " ");
	std::list<std::string>::iterator itt = input.begin();
	std::list<std::string> list = split((*itt), "-");

	if (list.size() != 3)
		return (err(E_INPUT(date)), false);

	std::list<std::string>::iterator it = list.begin();

	int year = 0;
	int month = 0;
	int day = 0;

	value = *it;
	year = std::atoi(value.c_str());

	if (value.length() != 4)
		return (false); 

	++it;
	value = *it;
	++it;

	if (value.length() != 2 || (*it).length() != 2)
		return (false); 

	month = std::atoi(value.c_str());
	day = std::atoi((*it).c_str());

	if (!verifTime(year, month, day, date))
		return (false);
	return (true);
}

static bool verifInput(std::string input)
{
	std::string value;
	std::list<std::string> list = split(input, " ");
	
	if (list.size() != 3)
		return (err(E_INPUT(input)), false);
	else if (!verifHyphen(input))
		return (false);
	value = giveInputInfo(input, 3);
	if (!verifValue(value))
		return (false);
	return (true);
}

static std::string makeMasterclass(int year, int month, int day)
{
	std::string masterClass = "";

	masterClass.append(std::to_string(year));
	masterClass.append("-");
	if (month < 10)
		masterClass.append("0");
	masterClass.append(std::to_string(month));
	masterClass.append("-");
	if (day < 10)
		masterClass.append("0");
	masterClass.append(std::to_string(day));
	return (masterClass);
}

// down grade the date

static std::string downGradeDate(std::string date)
{
	int year = 0;
	int month = 0;
	int day = 0;
	std::list<std::string> list = split(date, "-");
	std::list<std::string>::iterator it = list.begin();

	year = std::atof((*it).c_str());
	++it;
	month = std::atof((*it).c_str());
	++it;
	day = std::atof((*it).c_str());

	if (month == 1 && day == 1)
	{
		year--;
		month = 12;
		day = 31;
	}
	else if (day == 1)
	{
		month--;
		day = 30;
		if (month % 2 != 0)
			day = 31;
		else if (month == 2 && year % 4 == 0)
			day = 29;
		else if (month == 2 && year % 4 != 0)
			day = 28;
	}
	else
		day--;
	return (makeMasterclass(year, month, day));
}

static bool creationDateCmp(std::list<std::string> date)
{
	std::list<std::string>::iterator it = date.begin();
	int Year = std::atoi((*it++).c_str());
	int Month = std::atoi((*it++).c_str());
	int Day = std::atoi((*it).c_str());

	if (Year > 2009)
		return (true);
	else if (Year == 2009 && Month > 1)
		return (true);
	else if (Year == 2009 && Month == 1 && Day >= 2)
		return (true);
	return (false);
}

static std::string searchGoodDate(std::list<std::string> dateList, std::string date)
{
	std::list<std::string>::iterator it;

	while (date != "2009-01-02")
	{
		for (it = dateList.begin(); it != dateList.end(); ++it)
			if (*it == date)
				return (*it);
		if (!creationDateCmp(split(date, "-")))
			return ("Date is too low");
		date = downGradeDate(date);
	}
	return (date);
}

// find good rate 

static double searchDataRate(std::string date, std::list<std::string> data)
{
	std::list<std::string>::iterator it;
	std::list<std::string>::iterator it_sp;
	std::list<std::string> sp;

	for (it = data.begin(); it != data.end(); ++it)
	{
		sp = split((*it), ",");
		it_sp = sp.begin();
		if (date == (*it_sp))
			return (++it_sp, std::atof((*it_sp).c_str()));
	}
	if (date == "Date is too low")
		return (-1);
	return (0);
}

static double searchRate(std::list<std::string> data, int year, int month, int day)
{
	std::string date = "0";
	std::list<std::string>::iterator it;
	std::list<std::string>::iterator it_sp;
	std::list<std::string> sp;
	std::list<std::string> dataDateList;

	for (it = data.begin(); it != data.end(); ++it)
	{
		sp = split((*it), ",");
		it_sp = sp.begin();
		dataDateList.push_back((*it_sp));
	}
	date = searchGoodDate(dataDateList, makeMasterclass(year, month, day));
	return (searchDataRate(date, data));
}

static void rateData(std::list<std::string> data, std::string date, double *rate)
{
	int year = 0;
	int month = 0;
	int day = 0;
	std::string value;
	std::list<std::string> list = split(date, "-");
	std::list<std::string>::iterator it = list.begin();

	value = *it;
	year = std::atoi(value.c_str());
	++it;
	value = *it;
	++it;
	month = std::atoi(value.c_str());
	day = std::atoi((*it).c_str());
	*rate = searchRate(data, year, month, day);
}

void analyseData(std::list<std::string> data, std::list<std::string> input)
{
	double rate = 0;
	double dataRate = 0;
	std::string date;
	std::string value;
	std::list<std::string>::iterator it = input.begin();

	if (!input.empty() && ((*it) == "date | value" || (*it) == "\n"))
		++it;
	
	for (; it != input.end(); ++it)
	{
		if (!emptyInput((*it)) && verifInput((*it)))
		{
			date = giveInputInfo((*it), 1);
			value = giveInputInfo((*it), 3);
			rateData(data, date, &dataRate);
			rate = std::atof(value.c_str());
			if (dataRate == -1)
				std::cout << date << " => " << "Date is too low" << std::endl;
			else
				std::cout << date << " => " << value << " = " << rate * dataRate << std::endl;
		}
	}
}

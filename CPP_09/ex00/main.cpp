#include "BitcoinExchange.hpp"

static void err(std::string str)
{
	std::cerr << str << std::endl;
}

static std::list<std::string> split(std::string s, std::string c)
{
    std::list<std::string>    splitted;
    int last_space = 0;
    size_t space = s.find(c, 0);

    while (space != std::string::npos) {
        splitted.push_back(s.substr(last_space, space - last_space));
        last_space = space + 1;
        space = s.find(c, space + 1);
    }
    splitted.push_back(s.substr(last_space, s.size()));
    return (splitted);
}

static std::string gnl(std::string file)
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

static bool SimpleVerif(int argc, char **argv)
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

static bool emptyInput(std::string input)
{
	char c = 0;

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
	std::list<std::string> list = split(input, " ");
	std::list<std::string>::iterator it = list.begin();

	for (int i = 0; i < n; i++)
		++it;
	return ((*it));
}

static bool verifTime(int year, int month, int day, std::string date)
{
	time_t timestamp = time( NULL );
	struct tm *timeptr = localtime( & timestamp );;

	int t_year = 1900 + timeptr->tm_year;
	int t_month = timeptr->tm_mon + 1;
	int t_day = timeptr->tm_mday;

	if (year >= 0)
		return (err(E_INPUT_LOW_DATE(date)), false);
	else if (month >= 1 && month <= 12)
		return (err(E_INPUT(date)), false);
	else
	{
		if (month == 2 && year % 4 == 0 && (day < 1 || day > 29))
			return (err(E_INPUT(date)), false);
		else if (month == 2 && (day < 1 || day > 28) )
			return (err(E_INPUT(date)), false);
	}

	if (year > t_year)
		return (err(E_INPUT(date)), false);
	else if (year == t_year && month > t_month)
		return (err(E_INPUT(date)), false);
	else if (year == t_year && month == t_month && day > t_day)
		return (err(E_INPUT(date)), false);
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

	if (n != 3)
		return (err(E_INPUT(date)), false);

	for (int i = 0; date.c_str()[i]; i++)
	{
		c = date.c_str()[i];
		if (c == '-' || (c >= '0' && c <= '9'))
			return (err(E_INPUT(date)), false);
	}

	std::list<std::string> list = split(date, "-");

	if (list.size() != 3)
		return (err(E_INPUT(date)), false);

	std::list<std::string>::iterator it = list.begin();

	int year = 0;
	int month = 0;
	int day = 0;

	value = *it;
	year = std::atoi(value.c_str());

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
	int year = 0;
	int month = 0;
	int day = 0;
	std::string date;
	std::list<std::string> list = split(input, " ");


}

static int rateData(std::list<std::string> data, std::string line)
{
	// return le rate en fonction de l'input
}

static void analyseData(std::list<std::string> data, std::list<std::string> input)
{
	int rate = 0;
	std::string date;
	std::string value;
	std::list<std::string>::iterator it = input.begin();

	if ((*it) == "date | value\n" || (*it) == "\n")
		++it;
	
	for (; it != input.end(); ++it)
	{
		if (!emptyInput((*it)) && verifInput((*it)))
		{
			date = giveInputInfo((*it), 1);
			value = giveInputInfo((*it), 3);
			rate = rateData(data, (*it));
			std::cout << RPL(date, value, std::to_string(rate)) << std::endl;
		}
	}
	// fonction qui return l'annee ou le mois ou le jour en fonction d'un int 1 - 3
	// fonction qui donne le rate en fonction de la date / si impossible rate error
}

int main(int argc, char **argv)
{
	std::string file1;
	std::string data;
	std::list<std::string> fileList;
	std::list<std::string> dataList;

	if (!SimpleVerif(argc, argv))
		return (-1);

	file1 = gnl(argv[1]);
	data = gnl("data.csv");

	fileList = split(file1, "\n");
	dataList = split(data, "\n");

	for (std::list<std::string>::iterator it = fileList.begin(); it != fileList.end(); ++it)
		std::cout << *it << std::endl;

	if (fileList.empty() == false)
		analyseData(dataList, fileList);

	return (0);
}
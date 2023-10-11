#include "BitcoinExchange.hpp"

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
	if (fileList.empty() == false)
		analyseData(dataList, fileList);
	return (0);
}
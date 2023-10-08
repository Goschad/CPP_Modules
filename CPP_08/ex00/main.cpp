#include "easyfind.hpp"

int main(void)
{
	int valueForVect;
	int valueForList;
	std::list< int > containerList;
	std::vector< int > vectorList;

	for (int i = 1; i <= 10; i++)
	{
		vectorList.push_back(i);
		containerList.push_back(i);
	}

	valueForVect = 0;
	valueForList = 0;

	EasyFind( vectorList , valueForVect); // not found
	EasyFind( containerList , valueForList); // not found

	std::cout << std::endl;

	valueForVect = 5;
	valueForList = 5;

	EasyFind( vectorList , valueForVect); // found
	EasyFind( containerList , valueForList); // found

	std::cout << std::endl;

	valueForVect = 20;
	valueForList = 7;

	EasyFind( vectorList , valueForVect); // not found
	EasyFind( containerList , valueForList); // found

	std::cout << std::endl;

	valueForVect = 2;
	valueForList = 55;

	EasyFind( vectorList , valueForVect); // found
	EasyFind( containerList , valueForList); // not found

}
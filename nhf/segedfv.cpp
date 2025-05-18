#include "memtrace.h"
#include "segedfv.h"
#include <iostream>
#include <ctime>


int beker(std::istream& is) {
	std::string c;
	int i;
	std::getline(std::cin, c);
	try
	{
		i = std::stoi(c);

	}
	catch (const std::exception&)
	{
		return -1;
	}
	return i;
}


int veletlenSzam(int also, int felso) {
	srand(time(NULL)); 
	int finalNum = std::rand() % (also - felso + 1) + also;
	return finalNum;
}
#ifndef SEGED_H
#define SEGED_H

#include <random>



int beker(int maxInd) {
	int c;
	std::cin >> c;
	//input ellenőrzés
	return c;
}

int veletlenSzam(int also, int felso) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(also, felso);
	return dist(gen);
}

#endif
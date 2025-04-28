#ifndef MEGALLO_H
#define MEGALLO_H
#include "ido.h"
#include <string>

class Megallo {
	Ido erkezes, indulas;
	std::string nev;
public:
	Megallo(std::string nev = "") : nev(nev) {}
	Megallo(std::string nev, Ido erk, Ido ind): nev(nev), erkezes(erk), indulas(ind){}
	std::string getNev();
	Ido getErkezes();
	Ido getIndulas();
	friend std::ostream& operator<<(std::ostream& os, Megallo& m);
	
};

#endif

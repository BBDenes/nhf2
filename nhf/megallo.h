#ifndef MEGALLO_H
#define MEGALLO_H
#include "ido.h"
#include <string>

class Megallo {
	std::string nev;
	Ido erkezes, indulas;
public:
	Megallo(std::string nev = "") : nev(nev) {}
	Megallo(std::string nev, Ido erk, Ido ind): nev(nev), erkezes(erk), indulas(ind){
		if (ind < erk) throw std::invalid_argument("Nem megfelelo idopontok");
	}
	std::string getNev() const;
	Ido getErkezes();
	Ido getIndulas();
	friend std::ostream& operator<<(std::ostream& os, Megallo& m);
	
};

#endif

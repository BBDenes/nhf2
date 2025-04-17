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
	std::string getNev(){
		return nev;
	}
	Ido getErkezes() { return erkezes; }
	Ido getIndulas() { return indulas; }
	
};

std::ostream& operator<<(std::ostream& os, Megallo& megallo) {
	os << "Megallo: " << megallo.getNev();
	if (megallo.getErkezes().getOra() != -1 && megallo.getErkezes().getPerc() != -1) {
		os << " Erkezes: " << megallo.getErkezes();
	}
	os << " Indulas: " << megallo.getIndulas();
	return os;
}
#endif

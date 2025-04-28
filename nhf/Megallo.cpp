#include "megallo.h"

std::string Megallo::getNev() {
	return nev;
}

Ido Megallo::getErkezes() { return erkezes; }
Ido Megallo::getIndulas() { return indulas; }	

std::ostream& operator<<(std::ostream& os, Megallo& m) {
	os << m.nev << " - ";
	if (m.erkezes.getOra() != -1 && m.erkezes.getPerc() != -1) {
		os << " Erkezes:" << m.erkezes;
	}
	if (m.indulas.getOra() != -1 && m.indulas.getPerc() != -1)
		os << " Indulas: " << m.indulas;
	return os;
}
#include "memtrace.h"
#include "megallo.h"


Megallo::Megallo(std::string nev, Ido erk, Ido ind) : nev(nev), erkezes(erk), indulas(ind) {
	if (ind < erk) throw std::invalid_argument("Nem megfelelo idopontok");
}

std::string Megallo::getNev() const {
	return nev;
}

Ido Megallo::getErkezes() const { return erkezes; }
Ido Megallo::getIndulas() const { return indulas; }

void Megallo::fajlba(std::ostream& os) const {
	os << nev << ';';
	erkezes.fajlba(os);
	os << ';';
	indulas.fajlba(os);
}

std::ostream& operator<<(std::ostream& os, Megallo& m) {
	os << m.nev << " - ";
	if (m.erkezes.getOra() != -1 && m.erkezes.getPerc() != -1) {
		os << " Erkezes:" << m.erkezes;
	}
	if (m.indulas.getOra() != -1 && m.indulas.getPerc() != -1)
		os << " Indulas: " << m.indulas;
	return os;
}
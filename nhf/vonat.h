#ifndef VONAT_H
#define VONAT_H
#include "DynArray.hpp"
#include "ido.h"
#include "jegy.h"
#include "kocsi.h"
#include "megallo.h"

class Vonat {
	int id;
	std::string nev;
	DynArray<Kocsi> kocsik;
	DynArray<Megallo> megallok;
	Ido keses;
public:
	Vonat(int id = 0, std::string n = "", DynArray<Kocsi> kocsik = DynArray<Kocsi>(), DynArray<Megallo> mg = DynArray<Megallo>(), Ido keses = Ido(0,0)) : id(id), nev(n), kocsik(kocsik), megallok(mg), keses(keses) {}
	Vonat(const Vonat& rhs): id(rhs.id), nev(rhs.nev), kocsik(rhs.kocsik), megallok(rhs.megallok), keses(rhs.keses){}
	int osszFerohely();
	int getId();
	DynArray<Megallo> getMegallok();
	DynArray<Kocsi> getKocsik();
	Kocsi& operator[](size_t index);
	void modosit();
	friend std::ostream& operator<<(std::ostream& os, Vonat& v);
	friend std::istream& operator>>(std::istream& is, Vonat& v);
};

#endif
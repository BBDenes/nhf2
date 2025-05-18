#include "memtrace.h"
#include "DynArray.hpp"
#include "kocsi.h"
#include "segedfv.h"
#include "vonat.h"
#include <fstream>

int Kocsi::getFerohely() const { return ferohely; }
int Kocsi::getKerekesszek() const { return kerekesszek; }
int Kocsi::getKerekpar() const { return kerekpar; }
int Kocsi::getId() const { return id; }
DynArray<Jegy>& Kocsi::getJegyek() { return jegyek; }

void Kocsi::jegyHozzaad(int jaratszam, Megallo& honnan, Megallo& hova, std::string nev) {
	int szek;
	bool szabad = true;
	if (int(foglalt.len()) == ferohely) throw std::runtime_error("Tele a kocsi!");
	do {
		szek = veletlenSzam(1, ferohely);
		for (size_t i = 0; i < foglalt.len(); i++)
		{
			if (foglalt[i] == szek) szabad = false;
		}
	} while (!szabad);
	Helyjegy akt(Vonat::jegyId++, 1500, jaratszam, honnan, hova, nev, this->id, szek);
	jegyek += akt;
	foglalt += szek;
	std::cout << "A jegy:\n";
	akt.kiir(std::cout);
	std::ofstream kimenet(nev + ".txt",std::ios::app);
	akt.kiir(kimenet);
	std::cout << std::endl;
}

void Kocsi::fajlba(std::ostream& os) const {
	os << id << ';' << ferohely << ';' << kerekesszek << ';' << kerekpar;
}

std::ostream& operator<<(std::ostream& os, Kocsi& k) {
	os << "ID: " << k.id << ", Ferohely: " << k.ferohely << ", Ebbol szabad: " << k.ferohely - k.foglalt.len() << ", Kerekesszek: " << k.kerekesszek << ", Kerekpar: " << k.kerekpar <<std::endl;
	return os;
}
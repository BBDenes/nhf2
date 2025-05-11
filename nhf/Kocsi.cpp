#include "kocsi.h"
#include "segedfv.h"
#include "vonat.h"

int Kocsi::getFerohely() { return ferohely; }
int Kocsi::getKerekesszek() { return kerekesszek; }
int Kocsi::getKerekpar() { return kerekpar; }
int Kocsi::getId() { return id; }
DynArray<Jegy> Kocsi::getJegyek() { return jegyek; }

void Kocsi::jegyHozzaad(int jaratszam, Megallo honnan, Megallo hova, std::string nev) {
	int szek;
	bool szabad = true;
	if (foglalt.len() == ferohely) throw std::runtime_error("Tele a kocsi!");
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
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, Kocsi& k) {
	os << "ID: " << k.id << ", Ferohely: " << k.ferohely << "Ebbol szabad: " << k.ferohely - k.foglalt.len() << ", Kerekesszek: " << k.kerekesszek << ", Kerekpar: " << k.kerekpar <<std::endl;
	return os;
}
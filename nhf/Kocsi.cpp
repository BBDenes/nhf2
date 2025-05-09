#include "kocsi.h"

int Kocsi::getFerohely() { return ferohely; }
int Kocsi::getKerekesszek() { return kerekesszek; }
int Kocsi::getKerekpar() { return kerekpar; }
int Kocsi::getId() { return id; }
DynArray<Jegy> Kocsi::getJegyek() { return jegyek; }

void Kocsi::jegyHozzaad() {
	int szek;
	bool szabad = true;

	do {
		szek = veletlenSzam(1, ferohely);
		for (size_t i = 0; i < foglalt.len(); i++)
		{
			if (foglalt[i] == szek) szabad = false;
		}
	} while (!szabad);

	jegyek += Helyjegy(jegyek[-1].getId() + 1, 1500, );
}

std::ostream& operator<<(std::ostream& os, Kocsi& k) {
	os << "ID: " << k.id << ", Ferohely: " << k.ferohely << "Ebbol szabad: " << k.ferohely - k.foglalt.len() << ", Kerekesszek: " << k.kerekesszek << ", Kerekpar: " << k.kerekpar;
	return os;
}
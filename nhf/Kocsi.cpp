#include "kocsi.h"

int Kocsi::getFerohely() { return ferohely; }
int Kocsi::getKerekesszek() { return kerekesszek; }
int Kocsi::getKerekpar() { return kerekpar; }
int Kocsi::getId() { return id; }
DynArray<Jegy> Kocsi::getJegyek() { return jegyek; }

void Kocsi::jegyHozzaad(Jegy& jegy) {
	jegyek += jegy;
}

std::ostream& operator<<(std::ostream& os, Kocsi& k) {
	os << "ID: " << k.id << ", Ferohely: " << k.ferohely << ", Kerekesszek: " << k.kerekesszek << ", Kerekpar: " << k.kerekpar;
	return os;
}
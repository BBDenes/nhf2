#include "vonat.h"

int Vonat::osszFerohely() {
	size_t hossz = kocsik.len();
	int ferohely = 0;
	for (size_t i = 0; i < hossz; i++)
	{
		ferohely += kocsik[i].getFerohely();
	}
	return ferohely;
}

int Vonat::getId() {
	return id;
}

Kocsi& Vonat::operator[](size_t index) {
	//ide majd kivételkezelés
	return kocsik[index];
}

std::ostream& operator<<(std::ostream& os, Vonat& v) {
	os << "Vonat ID: " << v.id << " Nev: " << v.nev << " Keses: " << v.keses << "\nKocsik: " << std::endl;
	for (size_t i = 0; i < v.kocsik.len(); i++)
	{
		os << "\t" << v.kocsik[i] << std::endl;
	}
	std::cout << std::endl << "Megallok: " << std::endl;
	for (size_t i = 0; i < v.megallok.len(); i++)
	{
		os << "\t" << v.megallok[i] << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Vonat& v) {
	std::cout << "Work in progress..." << std::endl;
	return is;
}
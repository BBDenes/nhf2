#include "jegy.h"

void Jegy::kiir(std::ostream& os) const{
	os << "Jegy - Ár: " << ar << ", Járatszám: " << jaratszam;

}

int Helyjegy::getHely() { return szek; }
int Helyjegy::getKocsi() { return kocsiszam; }

void Helyjegy::kiir(std::ostream& os) const {
	os << "Helyjegy - " << nev << ", " << honnan << " -> " << hova
		<< ", Kocsi: " << kocsiszam << ", Hely: " << szek;
}
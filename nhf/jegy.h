#ifndef JEGY_H
#define JEGY_H
#include <iostream>

class Jegy {
	int id, ar, jaratszam;
public:
	Jegy(int id = 0, int ar = 0, int jaratszam = 0): id(id), ar(ar), jaratszam(jaratszam){}
	std::ostream& operator<<(std::ostream& os) {
		os << "Jegy" << "Ar: " << ar << "Jaratszam: " << jaratszam;
	}
};

#endif // !JEGY_H


class Helyjegy : public Jegy {
	std::string honnan, hova, nev;
	int kocsiszam, szek;
public:
	Helyjegy(std::string honnan="", std::string hova="", std::string nev="", int kocsi = 0, int szek = 0): honnan(honnan), hova(hova), nev(nev), kocsiszam(kocsi), szek(szek){}

	int getHely() { return szek; }
	int getKocsi() { return kocsiszam; }
};
#ifndef JEGY_H
#define JEGY_H
#include <iostream>
#include "megallo.h"

class Jegy {
	int id, ar, jaratszam;
public:
	Jegy(int id = 0, int ar = 0, int jaratszam = 0): id(id), ar(ar), jaratszam(jaratszam){}
	Jegy(const Jegy& rhs) : id(rhs.id), ar(rhs.ar), jaratszam(rhs.jaratszam) {}
	//friend std::ostream& operator<<(std::ostream& os, const Jegy& jegy);
	int getId();
	virtual void kiir(std::ostream& os);
	virtual ~Jegy() = default;
};



class Helyjegy : public Jegy {
	std::string nev;
	Megallo honnan, hova;
	int kocsiszam, szek, helyAr;
public:
	Helyjegy(int id, int ar, int jaratszam,
		Megallo honnan = Megallo(), Megallo hova = Megallo(), std::string nev = "",
		int kocsi = 0, int szek = 0, int helyar = 650)
		: Jegy(id, ar, jaratszam),
		honnan(honnan), hova(hova), nev(nev),
		kocsiszam(kocsi), szek(szek), helyAr(helyar) {}
	Helyjegy(const Helyjegy& rhs) : Jegy(rhs),
		honnan(rhs.honnan), hova(rhs.hova), nev(rhs.nev),
		kocsiszam(rhs.kocsiszam), szek(rhs.szek), helyAr(rhs.helyAr) {}

	int getHely();
	int getKocsi();

	void kiir(std::ostream& os) override;
};


#endif // !JEGY_H
#ifndef JEGY_H
#define JEGY_H
#include "memtrace.h"
#include <iostream>
#include "megallo.h"

class Jegy {
	int id, ar, jaratszam;
public:

	//@brief Default konstruktor
	Jegy(int id = 0, int ar = 0, int jaratszam = 0): id(id), ar(ar), jaratszam(jaratszam){}

	//@brief Másoló ctor
	Jegy(const Jegy& rhs) : id(rhs.id), ar(rhs.ar), jaratszam(rhs.jaratszam) {}
	int getId();

	/*
	* Kiíró függvény, ami kiírja a jegy adatait
	* @param os: az ostream, ahova ír
	*/
	virtual void kiir(std::ostream& os) const;
	virtual ~Jegy() = default;
};



class Helyjegy : public Jegy {
	std::string nev;
	Megallo honnan, hova;
	int kocsiszam, szek, helyAr;
public:

	//@brief Helyjegy ctor, az id, ar, jaratszam kötelező
	Helyjegy(int id, int ar, int jaratszam,
		Megallo honnan = Megallo(), Megallo hova = Megallo(), std::string nev = "",
		int kocsi = 0, int szek = 0, int helyar = 650)
		: Jegy(id, ar, jaratszam),nev(nev),
		honnan(honnan), hova(hova),
		kocsiszam(kocsi), szek(szek), helyAr(helyar) {}

	//@brief Másolo ctor
	Helyjegy(const Helyjegy& rhs) : Jegy(rhs), nev(rhs.nev),
		honnan(rhs.honnan), hova(rhs.hova),
		kocsiszam(rhs.kocsiszam), szek(rhs.szek), helyAr(rhs.helyAr) {}

	int getHely() const;
	int getKocsi() const;

	/*
	* Kiíró függvény, ami kiírja a jegy adatait
	* @param os: az ostream, ahova ír
	*/
	void kiir(std::ostream& os) const override;
};


#endif // !JEGY_H
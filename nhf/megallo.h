#ifndef MEGALLO_H
#define MEGALLO_H
#include "memtrace.h"
#include "ido.h"
#include <string>

class Megallo {
	std::string nev;
	Ido erkezes, indulas;
public:

	//@brief Default ctor
	Megallo(std::string nev = "") : nev(nev) {}

	//Konstruktor időpontokkal, ami std::invalid argument kivételt dob, ha az indulási idő korábban van, mint az érkezés
	Megallo(std::string nev, Ido erk, Ido ind);
	std::string getNev() const;
	Ido getErkezes() const;
	Ido getIndulas() const;

	/*
	* Kiírja a megálló adatait a fájlban tárolt formátumban
	* @param os: ostream, ahova írja az adatokat
	*/
	void fajlba(std::ostream& os) const;

	/*
	* Kiíró operátor felhasználóbarát formátumban
	* @param os: ostream, ahova ír
	* @returns os
	*/
	friend std::ostream& operator<<(std::ostream& os, Megallo& m);
	
};

#endif

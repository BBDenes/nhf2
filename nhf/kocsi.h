#ifndef KOCSI_H
#define KOCSI_H
#include "memtrace.h"
#include "DynArray.hpp"
#include "jegy.h"

class Kocsi {
	int id, ferohely, kerekesszek, kerekpar;
	DynArray<Jegy> jegyek;
	DynArray<int> foglalt;
public:

	//@brief Default ctor
	Kocsi(int id = 0, int fh = 0, int ksz = 0, int kp = 0) : id(id), ferohely(fh), kerekesszek(ksz), kerekpar(kp), jegyek(DynArray<Jegy>()), foglalt(DynArray<int>()) {}
	int getFerohely() const;
	int getKerekesszek() const;
	int getKerekpar() const;
	int getId() const;
	DynArray<Jegy>& getJegyek();

	/*
	*	Hozzáadja a megadott paraméterű jegyeket a kocsihoz, majd kiírja a konzolra és egy, a névvel megegyező nevű fájlba
	*	@param jaratszam: A vonat azonosítója
	*	@param honnan: Az indulási megálló
	*	@param hova: Az érkezési megálló
	*	@param nev: Az utas neve
	*/
	void jegyHozzaad(int jaratszam, Megallo& honnan, Megallo &hova, std::string nev);

	/*
	*	Kiírja a megadott ostreamre a kocsi adatait abban a formátumban, ahogy a txt fájlokban van tárolva
	*	@param os: Az ostream, ahova kiírja az adatokat
	*/
	void fajlba(std::ostream& os) const;

	/*
	*	kiíró operátor, felhasználóbarát megjelenítésre
	*	@param os: ostream, ahova kiírja az adatokat
	*	@param k: A kocsi
	*	@returns os
	*/
	friend std::ostream& operator<<(std::ostream& os, Kocsi& k);
};

#endif // !KOCSI_H

#ifndef KOCSI_H
#define KOCSI_H

#include "DynArray.hpp"
#include "jegy.h"
#include "segedfv.h"

class Kocsi {
	int id, ferohely, kerekesszek, kerekpar;
	DynArray<Jegy> jegyek;
	DynArray<int> foglalt;
public:
	Kocsi(int id = 0, int fh = 0, int ksz = 0, int kp = 0) : id(id), ferohely(fh), kerekesszek(ksz), kerekpar(kp), jegyek(DynArray<Jegy>()), foglalt(DynArray<int>()) {}
	int getFerohely();
	int getKerekesszek();
	int getKerekpar();
	int getId();
	DynArray<Jegy> getJegyek();
	void jegyHozzaad(int jaratszam, Megallo honnan, Megallo hova, std::string nev);
	friend std::ostream& operator<<(std::ostream& os, Kocsi& k);
};

#endif // !KOCSI_H

#ifndef JEGY_H
#define JEGY_H
#include <iostream>

class Jegy {
	int id, ar, jaratszam;
public:
	Jegy(int id = 0, int ar = 0, int jaratszam = 0): id(id), ar(ar), jaratszam(jaratszam){}
	Jegy(const Jegy& rhs) : id(rhs.id), ar(rhs.ar), jaratszam(rhs.jaratszam) {}
	virtual void kiir(std::ostream& os) const;
	virtual ~Jegy() = default;
};



class Helyjegy : public Jegy {
	std::string honnan, hova, nev;
	int kocsiszam, szek;
public:
	Helyjegy(int id, int ar, int jaratszam,
		std::string honnan = "", std::string hova = "", std::string nev = "",
		int kocsi = 0, int szek = 0)
		: Jegy(id, ar, jaratszam), 
		honnan(honnan), hova(hova), nev(nev),
		kocsiszam(kocsi), szek(szek) {}
	Helyjegy(const Helyjegy& rhs) : Jegy(rhs),
		honnan(rhs.honnan), hova(rhs.hova), nev(rhs.nev),
		kocsiszam(rhs.kocsiszam), szek(rhs.szek) {}

	int getHely();
	int getKocsi();


	void kiir(std::ostream& os) const override;
};


#endif // !JEGY_H
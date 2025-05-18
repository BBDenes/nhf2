#include "memtrace.h"
#include <iostream>
#include <fstream>
#include "DynArray.hpp"
#include "ido.h"
#include "megallo.h"
#include "vonat.h"
#include "menu.h"
#include "predicates.h"
#include "gtest_lite.h"


#ifndef CPORTA
//amennyiben a fájlbeolvasás nem sikerül, tudjon miből dolgozni a program
void fallback(DynArray<Vonat>& vonatok) {

	//tesztadatok megadása

	DynArray<Megallo> megallok1, megallok2, megallok3;
	DynArray<Kocsi> tesztKocsik;
	megallok1 += Megallo("Szombathely", Ido(-1, -1), Ido(10, 20));
	megallok1 += Megallo("BP_Kelenfold", Ido(14, 30), Ido(-1, -1));
	megallok2 += Megallo("BP-Deli", Ido(-1, -1), Ido(13, 35));
	megallok2 += Megallo("Szekesfehervar", Ido(14, 21), Ido(14, 22));
	megallok2 += Megallo("Nagykanizsa", Ido(16, 44), Ido(-1, -1));

	megallok3 += Megallo("Szombathely", Ido(-1, -1), Ido(12, 20));
	megallok3 += Megallo("BP_Keleti", Ido(16, 30), Ido(-1, -1));

	tesztKocsik += Kocsi(411, 50, 0, 0);
	tesztKocsik += Kocsi(412, 75, 2, 10);

	vonatok += Vonat(925, "Savaria IC", tesztKocsik, megallok1, Ido(0, 5));
	vonatok += Vonat(854, "Topart IC", tesztKocsik, megallok2, Ido(1, 20));
	vonatok += Vonat(927, "Savaria IC", tesztKocsik, megallok3, Ido(0, 15));

}

int main() {

	//fájlból beolvasás teszt
	DynArray<Vonat> vonatok;
	try
	{
		vonatok.fajlbol("vonatok.txt");
	}
	catch (const std::exception&)
	{
		std::cout << "Teszt vonatok hasznalata... " << std::endl;
		fallback(vonatok);
	}

	std::cout << vonatok;
	fomenu(vonatok);
	
	vonatok.fajlba("vonatokKi.txt");

	return 0;
}

#endif
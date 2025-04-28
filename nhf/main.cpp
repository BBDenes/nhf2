#include <iostream>
#include <fstream>
#include "DynArray.hpp"
#include "ido.h"
#include "megallo.h"
#include "vonat.h"
#include "menu.h"

//teszt1, Hozzáad 2 tesztvonatot a listához megállókkal és 2-2 kocsival
void test1(DynArray<Vonat>& vonatok) {

	//tesztadatok megadása

	DynArray<Megallo> megallok1, megallok2;
	DynArray<Kocsi> tesztKocsik;
	megallok1 += Megallo("Szombathely", Ido(-1, -1), Ido(10, 20));
	megallok1 += Megallo("BP_Kelenfold", Ido(14, 30), Ido(-1, -1));
	megallok2 += Megallo("Nagykanizsa", Ido(-1, -1), Ido(12, 30));
	megallok2 += Megallo("BP-Deli", Ido(16, 40), Ido(-1, -1));
	tesztKocsik += Kocsi(411, 50, 0, 0);
	tesztKocsik += Kocsi(412, 75, 2, 10);

	vonatok += Vonat(925, "Savaria", tesztKocsik, megallok1);
	vonatok += Vonat(854, "Topart", tesztKocsik, megallok2);

	for (size_t i = 0; i < vonatok.len(); ++i) {
		std::cout << vonatok[i] << std::endl;
	}

}

int main(void) {

	DynArray<Vonat> vonatok;

	//pár vonat hozzáadása fájlbeolvasás helyett
	vonatok += Vonat(925, "Savaria");
	vonatok += Vonat(854, "Topart");

	test1(vonatok);

	fomenu(vonatok);
	
	for (size_t i = 0; i < vonatok.len(); ++i) {
		std::cout << vonatok[i] << std::endl;
	}

}
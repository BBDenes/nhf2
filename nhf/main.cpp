#include <iostream>
#include <fstream>
#include "DynArray.hpp"
#include "ido.h"
#include "megallo.h"
#include "vonat.h"
#include "menu.h"
#include "predicates.h"

//teszt1, Hozzáad 2 tesztvonatot a listához megállókkal és 2-2 kocsival
void test1(DynArray<Vonat>& vonatok) {

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

//megkeressük, van-e 925-ös, 854-es, és 1-es ID-jű vonat
void test2(DynArray<Vonat>& vonatok) {
	std::cout << "925: " << std::boolalpha << vonatok.includes(925) << ", 854: " << vonatok.includes(854) << ", 1: " << vonatok.includes(1) << std::endl;
	
}

void filterTest(DynArray<Vonat>& vonatok) {
	DynArray<Vonat> vonatok2 = vonatok.filter(Indulas("Szombathely"));
	vonatok2 = vonatok2.filter(Vegallomas("BP_Keleti"));
	std::cout << vonatok2 << std::endl;

}

void keresTest(DynArray<Vonat>& vonatok) {
	try
	{
		Vonat aktualis = vonatok.keres(vonatId(123));

	}
	catch (const std::exception& e)
	{
		std::cerr << "HIBA: " << e.what() << std::endl;
	}
}

int main(void) {

	DynArray<Vonat> vonatok;

	test1(vonatok);
	//test2(vonatok);
	//filterTest(vonatok);
	keresTest(vonatok);

	//főmenü: vonat manuális hozzáadásához
	fomenu(vonatok);
	

}
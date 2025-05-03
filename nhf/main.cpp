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

	DynArray<Megallo> megallok1, megallok2;
	DynArray<Kocsi> tesztKocsik;
	megallok1 += Megallo("Szombathely", Ido(-1, -1), Ido(10, 20));
	megallok1 += Megallo("BP_Kelenfold", Ido(14, 30), Ido(-1, -1));
	megallok2 += Megallo("BP-Deli", Ido(-1, -1), Ido(13, 35));
	megallok2 += Megallo("Szekesfehervar", Ido(14, 21), Ido(14, 22));
	megallok2 += Megallo("Nagykanizsa", Ido(16, 44), Ido(-1, -1));
	tesztKocsik += Kocsi(411, 50, 0, 0);
	tesztKocsik += Kocsi(412, 75, 2, 10);

	vonatok += Vonat(925, "Savaria IC", tesztKocsik, megallok1, Ido(0, 5));
	vonatok += Vonat(854, "Topart IC", tesztKocsik, megallok2, Ido(1, 20));

	for (size_t i = 0; i < vonatok.len(); ++i) {
		std::cout << vonatok[i] << std::endl;
	}
}

//megkeressük, van-e 925-ös, 854-es, és 1-es ID-jű vonat
void test2(DynArray<Vonat>& vonatok) {
	std::cout << "925: " << std::boolalpha << vonatok.includes(925) << ", 854: " << vonatok.includes(854) << ", 1: " << vonatok.includes(1) << std::endl;
	
}

int main(void) {

	DynArray<Vonat> vonatok;

	test1(vonatok);
	test2(vonatok);
	std::cout << "\n" << vonatok.keres(vonatId(925)) << std::endl;
	vonatok.keres(vonatId(925)).modosit();
	//főmenü: vonat manuális hozzáadásához
	//fomenu(vonatok);
	

}
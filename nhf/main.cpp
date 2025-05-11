#include <iostream>
#include <fstream>
#include "DynArray.hpp"
#include "ido.h"
#include "megallo.h"
#include "vonat.h"
#include "menu.h"
#include "predicates.h"
#include "gtest_lite.h"
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

void gTetst(DynArray<Vonat>& vonatok) {
	TEST(includes, jo_id) {
		EXPECT_EQ(true, vonatok.includes(925));
	}END

	TEST(megallo, idoutazuas) {
		//a legelso vonathoz megprobalunk hozzaadni egy megállót, ahol előbb indulunk, minthogy megérkeznénk
		EXPECT_THROW(vonatok[0].getMegallok() += Megallo("Teszt", Ido(12, 21), Ido(11, 12)), std::invalid_argument);
	}END

	TEST(vonat, idoutazuas) {
		//egy olyan vonatot próbálunk hozzáadni, ami előbb ér a végállomásra, mint amikor indul
		DynArray<Megallo> tesztmegallok;
		tesztmegallok += Megallo("Indulas", Ido(-1, -1), Ido(12, 21));
		tesztmegallok += Megallo("Vegallomas", Ido(11, 20), Ido(-1, -1));
		EXPECT_THROW(vonatok += Vonat(123, "Teszt", DynArray<Kocsi>(), tesztmegallok, Ido(0, 0)), std::invalid_argument);
	}END

	TEST(keres, rossz_id) {
		EXPECT_THROW(vonatok.keres(vonatId(10)), std::invalid_argument);
	}END

}

int main(void) {

	DynArray<Vonat> vonatok;

	//test1(vonatok);
	//test2(vonatok);
	//filterTest(vonatok);
	//keresTest(vonatok);
	//gTetst(vonatok);

	std::ifstream f("vonatok.txt");
	f >> vonatok;
	std::cout << vonatok;

	//főmenü: vonat manuális hozzáadásához
	fomenu(vonatok);
	

}
#include "menu.h"
#include "DynArray.hpp"
#include "kocsi.h"
#include "vonat.h"
#include "predicates.h"

void jegyvasarlas() {}

//bemenetek kezelésére @param maxInd: a maximum index ami még elfogadható
int beker(int maxInd) {
	int c;
	std::cin >> c;
	//input ellenőrzés
	return c;
}

void fomenu(DynArray<Vonat>& vonatok) {
	std::cout << "Fomenu - Valasztani a menupont sorszamaval lehet, kilepeshez -1\n"
		<< "\t1. Vonatjegy vasarlasa\n" << "\t2. Vonatok kezelese" << std::endl;
	int choice = beker(2);

	if (choice == -1)
	{
		exit(1);
	}
	else if (choice == 1) {
		jegyvasarlas();
	}
	else if (choice == 2) {
		kezeles(vonatok);
	}
}

void kezeles(DynArray<Vonat>& vonatok) {
	std::cout << "Mit szeretne tenni?\n" << "\t1. Vonat hozzaadasa es kezelese\n" << "\t2. Vonat eltavolitasa\n" << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		int id = 0;

		std::cout << "Adja meg a modositani kivant vonat azonosítóját: ";
		std::cin >> id;
		if (vonatok.includes(id)) {
			std::cout << "Meglevo vonat kezelse..." << std::endl;
			Vonat talalat = vonatok.keres(vonatId(id));
			talalat.modosit();
		}
		std::cout << "Ilyen azonositoval nem letezik vonat, uj vonat letrehozasa..." << std::endl;



		std::cout << std::endl << "Adja meg a vonat nevét: ";
		std::string nev;
		std::cin >> nev;

		std::cout << std::endl << "Hány kocsija legyen?: ";
		int db;
		std::cin >> db;
		std::cout << std::endl;
		DynArray<Kocsi> kocsik = DynArray<Kocsi>();
		for (int i = 0; i < db; i++)
		{
			std::cout << " Kocsi azonositoja, ferohelye, kerekesszekes- es kerekparos utazasra alkalmas helyek szama: (formátum: id ferohely kerekesszek kerekpar)" << std::endl;
			int kocsiId, feroh, kerekesszek, kerekpar;
			std::cin >> kocsiId >> feroh >> kerekesszek >> kerekpar;
			kocsik += Kocsi(kocsiId, feroh, kerekesszek, kerekpar);
		}


		vonatok += Vonat(id, nev, kocsik);
	}
}



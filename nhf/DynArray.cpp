#include "DynArray.hpp"
#include "vonat.h"


void DynArray<Vonat>::kezeles() {
	std::cout << "Mit szeretne tenni?\n" << "\t1. Vonat hozzaadasa\n" << "\t2. Vonat eltavolitasa\n" << "\t3. Vonat kezelese" << std::endl;
	int choice;
	std::cin >> choice;
	//input error handling coming soon...
	if (choice == 1) {

		std::cout << "Adja meg a vonat azonosítóját: ";
		int id;
		std::cin >> id;

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
			std::cout << " Kocsi azonositoja, ferohelye, kerekesszekes- és kerekparos utazasra alkalmas helyek szama: (formátum: id férőhely kerekesszek kerekpar)" << std::endl;
			int kocsiId, feroh, kerekesszek, kerekpar;
			std::cin >> kocsiId >> feroh >> kerekesszek >> kerekpar;
			kocsik += Kocsi(kocsiId, feroh, kerekesszek, kerekpar);
		}
		for (size_t i = 0; i < kocsik.len(); ++i) {
			std::cout << "Kocsi ID: " << kocsik[i].getId() << "\n";
		}

		*this += Vonat(id, nev, kocsik);


	}
}

//work in progress...
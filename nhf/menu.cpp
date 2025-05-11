#include "menu.h"
#include "DynArray.hpp"
#include "kocsi.h"
#include "vonat.h"
#include "predicates.h"
#include "segedfv.h"

void jegyvasarlas(DynArray<Vonat>& vonatok) {
	std::cout << "Adja meg a kiindulo allomast: ";
	std::string start;
	std::string end;
	std::getline(std::cin, start);
	std::cout << std::endl << "Adja meg a vegallomast: ";
	std::getline(std::cin, end);

	DynArray<Vonat> szurt = vonatok.filter(Indulas(start));
	szurt = szurt.filter(Vegallomas(end));
	std::cout << "Az elerheto vonatok:\n" << szurt << std::endl;

	std::cout << "Melyik azonositoju vonatra szeretne jegyet venni?: ";
	int choice = beker(-1);
	try
	{
		Vonat& aktualis = vonatok.keres(vonatId(choice));
		std::string nev;
		std::cout << "Adja meg a nevet: ";
		std::cin.ignore();
		std::getline(std::cin, nev);
		int kocsi;
		DynArray<Kocsi>& kocsik = aktualis.getKocsik();
		std::cout << "A vonaton talalhato kocsik:\n" << kocsik << std::endl;
	
		do {
			std::cout << "Melyik kocsiba szeretne foglalni?: ";
			std::cin >> kocsi;
			std::cout << std::endl;

		} while (!(kocsik.includes(kocsi)));
		Kocsi& aktKocsi = kocsik.keres(vonatId(kocsi));
		aktKocsi.jegyHozzaad(aktualis.getId(), aktualis.getMegallok()[0], aktualis.getMegallok()[-1], nev);
		std::cout << kocsik.keres(vonatId(kocsi));

		
	}
	catch (const std::exception& e)
	{
		std::cerr << "HIBA: " << e.what() << std::endl;
		return;
	}

}

void fomenu(DynArray<Vonat>& vonatok) {
	std::string choice;
	do {
		std::cout << "Fomenu - Valasztani a menupont sorszamaval lehet, kilepeshez -1\n"
			<< "\t1. Vonatjegy vasarlasa\n" << "\t2. Vonatok kezelese" << std::endl;
		std::getline(std::cin, choice);
		if (choice == "1") {
			jegyvasarlas(vonatok);
		}
		else if (choice == "2") {
			kezeles(vonatok);
		}
		else if(choice != "-1") {
			std::cout << "Nem megfelelo menupont!" << std::endl;
		}
	} while (choice != "-1");
}

void kezeles(DynArray<Vonat>& vonatok) {
	std::cout << "Mit szeretne tenni?\n" << "\t1. Vonat hozzaadasa es kezelese\n" << "\t2. Vonat eltavolitasa\n\t-1. Menu" << std::endl;
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



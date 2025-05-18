#include "memtrace.h"
#include "DynArray.hpp"
#include "menu.h"
#include "kocsi.h"
#include "vonat.h"
#include "predicates.h"
#include "segedfv.h"

void jegyvasarlas(DynArray<Vonat>& vonatok, std::istream& is) {
	std::cout << "Adja meg a kiindulo allomast: ";
	std::string start;
	std::string end;
	std::getline(is, start);
	std::cout << std::endl << "Adja meg a vegallomast: ";
	std::getline(is, end);

	DynArray<Vonat> szurt = vonatok.filter(Allomasok(start, end));
	if (szurt.len() == 0) {
		std::cout << "Ilyen parameterekkel nincs vonat!";
		return;
	}
	std::cout << "Az elerheto vonatok:\n" << szurt << std::endl;

	std::cout << "Melyik azonositoju vonatra szeretne jegyet venni?: ";
	int choice = beker(std::cin);
	if (choice == -1) return;
	try
	{
		Vonat& aktualis = vonatok.keres(vonatId(choice));
		std::string nev;
		std::cout << "Adja meg a nevet: ";
		std::getline(is, nev);
		int kocsi;
		DynArray<Kocsi>& kocsik = aktualis.getKocsik();
		std::cout << "A vonaton talalhato kocsik:\n" << kocsik << std::endl;
	
		do {
			std::string tmp;
			std::cout << "Melyik kocsiba szeretne foglalni?: ";
			std::getline(is, tmp);
			std::cout << std::endl;
			kocsi = std::stoi(tmp);
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
		std::cout << std::endl << "Fomenu - Valasztani a menupont sorszamaval lehet, kilepeshez -1\n"
			<< "\t1. Vonatjegy vasarlasa\n" << "\t2. Vonatok kezelese" << std::endl;
		std::getline(std::cin, choice);
		if (choice == "1") {
			jegyvasarlas(vonatok, std::cin);
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
	int choice = beker(std::cin);
	if (choice == 1) {
		int id = 0;

		std::cout << "Adja meg a modositani kivant vonat azonositojat: ";
		id = beker(std::cin);
		if (id == -1) return;
		if (vonatok.includes(id)) {
			std::cout << "Meglevo vonat kezelse..." << std::endl;
			Vonat talalat = vonatok.keres(vonatId(id));
			try {
				talalat.modosit();
				return;
			}
			catch (std::exception& e) {
				std::cout << "HIBA! " << e.what() << std::endl;
				return;
			}
		}
		std::cout << "Ilyen azonositoval nem letezik vonat, uj vonat letrehozasa..." << std::endl;



		std::cout << std::endl << "Adja meg a vonat nevét: ";
		std::string nev;
		std::getline(std::cin, nev);

		std::cout << std::endl << "Hány kocsija legyen?: ";
		int db = beker(std::cin);
		if (db == -1) return;
		std::cout << std::endl;
		DynArray<Kocsi> kocsik = DynArray<Kocsi>();
		for (int i = 0; i < db; i++)
		{
			std::cout << " Kocsi azonositoja, ferohelye, kerekesszekes- es kerekparos utazasra alkalmas helyek szama: (formátum: id ferohely kerekesszek kerekpar)" << std::endl;
			int kocsiId, feroh, kerekesszek, kerekpar;
			std::cin >> kocsiId >> feroh >> kerekesszek >> kerekpar;
			
			if (!kocsik.includes(kocsiId)) {
				kocsik += Kocsi(kocsiId, feroh, kerekesszek, kerekpar);
			}
		}
		std::cin.ignore();

		DynArray<Megallo> megallok;
		std::string ujNev;
		std::cout << "Adja meg az indulo allomas nevet: " << std::endl;
		std::getline(std::cin, ujNev);
		std::cout << "Adja meg az indulasi idopontot(OO PP formatumban): ";
		try {
			int io, ip;
			std::cin >> io >> ip;
			megallok += Megallo(ujNev, Ido(-1, -1), Ido(io, ip));
		}
		catch (std::exception& e) { std::cout << "HIBA! " << e.what() << std::endl; return; }

		std::cout << "Adja meg az erkezesi allomas nevet: " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, ujNev);
		std::cout << "Adja meg az erkezesi idopontot(OO PP formatumban): ";
		try {
			int eo, ep;
			std::cin >> eo >> ep;
			megallok += Megallo(ujNev, Ido(eo, ep), Ido(-1, -1));
			vonatok += Vonat(id, nev, kocsik, megallok);
		}
		catch (std::exception& e) { std::cout << "HIBA! " << e.what() << std::endl; return; }

		std::cin.ignore();

	}
	else if (choice == 2) {
		int id;
		std::cout << "Adja meg a torolni kivant vonat azonositojat: ";
		id = beker(std::cin);
		std::cout << std::endl;
		for (size_t i = 0; i < vonatok.len(); i++)
		{
			if (vonatok[i].getId() == id) {
				vonatok.torol(i);
				std::cout << "Vonat torolve!" << std::endl;
			}
		}
	}
	
}



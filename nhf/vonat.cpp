#include "vonat.h"

int Vonat::osszFerohely() {
	size_t hossz = kocsik.len();
	int ferohely = 0;
	for (size_t i = 0; i < hossz; i++)
	{
		ferohely += kocsik[i].getFerohely();
	}
	return ferohely;
}

int Vonat::getId() {
	return id;
}

DynArray<Megallo> Vonat::getMegallok() {
	return megallok;
}

DynArray<Kocsi> Vonat::getKocsik() { return kocsik; }

Kocsi& Vonat::operator[](size_t index) {
	//ide majd kivételkezelés
	return kocsik[index];
}

void Vonat::modosit()
{
	int valasztas = 0;
	while (valasztas != -1) {
		std::cout << "Mit szeretne modositani?\n\t1. Nev modositas\n\t2. Kocsi hozzaadasa\n\t3. Kocsi eltavolitasa\n\t4. Megallo hozzaadasa\n\t5 Megallo eltavolitasa" << std::endl;
		std::cin >> valasztas;
		std::string ujNev;
		switch (valasztas)
		{
		case 1:
			std::cout << "Adja meg az új nevet: ";
			std::cin.ignore();
			std::getline(std::cin, ujNev);
			nev = ujNev;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << " Kocsi azonositoja, ferohelye, kerekesszekes- es kerekparos utazasra alkalmas helyek szama: (formátum: id ferohely kerekesszek kerekpar)" << std::endl;
			int kocsiId, feroh, kerekesszek, kerekpar;
			std::cin >> kocsiId >> feroh >> kerekesszek >> kerekpar;
			kocsik += Kocsi(kocsiId, feroh, kerekesszek, kerekpar);
			break;
		case 3:
			int id;
			std::cout << "Adja meg a torolni kivant kocsi azonositojat: ";
			std::cin >> id;
			std::cout << std::endl;
			for (int i = 0; i < kocsik.len(); i++)
			{
				if (kocsik[i].getId() == id) {
					kocsik.torol(i);
					std::cout << "Kocsi torolve!" << std::endl;
				}
			}
			break;
		case 4:
			std::cout << "Adja meg az allomas nevet: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, ujNev);
			std::cout << "Adja meg az erkezesi es indulasi idopontot(OO PP OO PP formatumban, az erkezessel kezdve): ";
			int eo, ep, io, ip;
			std::cin >> eo >> ep >> io >> ip;
			megallok.insert(Megallo(ujNev, Ido(eo, ep), Ido(io, ip)));

			//std::cout << megallok;
			break;
		case 5:
			std::cout << "Adja meg a torolni kivant megallo nevet: ";
			std::cin >> ujNev;
			std::cout << std::endl;
			for (size_t i = 0; i < megallok.len(); i++)
			{
				if (megallok[i].getNev() == ujNev) {
					megallok.torol(i);
					std::cout << "Megallo torolve!" << std::endl;
				}


			}
			break;
		default:
			break;
		}
		std::cout << "A modositott vonat: " << *this << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Vonat& v) {
	os << "Vonat ID: " << v.id << " Nev: " << v.nev << " Keses: " << v.keses << "\nKocsik: " << std::endl;
	for (size_t i = 0; i < v.kocsik.len(); i++)
	{
		os << "\t" << v.kocsik[i] << std::endl;
	}
	std::cout << std::endl << "Megallok: " << std::endl;
	for (size_t i = 0; i < v.megallok.len(); i++)
	{
		os << "\t" << v.megallok[i] << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Vonat& v) {
	std::cout << "Work in progress..." << std::endl;
	return is;
}
#include "memtrace.h"
#include "vonat.h"
#include "segedfv.h"
#include "predicates.h"
#include <sstream>

int Vonat::jegyId = 0;

Vonat::Vonat(int id, std::string n, DynArray<Kocsi> kocsik, DynArray<Megallo> mg, Ido keses) : id(id), nev(n), kocsik(kocsik), megallok(mg), keses(keses) {
	if (mg.len() != 0 && mg[-1].getErkezes() < mg[0].getIndulas()) throw std::invalid_argument("Nem megfelelo indulasi es erkezesi idopontok!");

}

int Vonat::getId() const {
	return id;
}

DynArray<Megallo>& Vonat::getMegallok() {
	return megallok;
}

DynArray<Kocsi>& Vonat::getKocsik()  { return kocsik; }

Kocsi& Vonat::operator[](size_t index) const {
	if (index >= kocsik.len() || index < 0) throw std::invalid_argument("Nem megfelelo index");
	return kocsik[index];
}

void Vonat::nevMod() {
	std::string ujNev;
	std::cout << "Adja meg az új nevet: ";
	std::getline(std::cin, ujNev);
	nev = ujNev;
	std::cout << std::endl;
}

void Vonat::kocsiFelvetel() {
	std::cout << " Kocsi azonositoja, ferohelye, kerekesszekes- es kerekparos utazasra alkalmas helyek szama: (formátum: id ferohely kerekesszek kerekpar)" << std::endl;
	int kocsiId, feroh, kerekesszek, kerekpar;
	std::cin >> kocsiId >> feroh >> kerekesszek >> kerekpar;
	std::cin.ignore();
	if (kocsik.includes(kocsiId)) {
		throw std::runtime_error("Ilyen azonositoju kocsi mar van!");
	}
	kocsik += Kocsi(kocsiId, feroh, kerekesszek, kerekpar);
}

void Vonat::kocsiTorol() {
	int id;
	std::cout << "Adja meg a torolni kivant kocsi azonositojat: ";
	id = beker(std::cin);
	std::cout << std::endl;
	for (size_t i = 0; i < kocsik.len(); i++)
	{
		if (kocsik[i].getId() == id) {
			kocsik.torol(i);
			std::cout << "Kocsi torolve!" << std::endl;
		}
	}
}

void Vonat::megalloFelvetel() {
	std::string ujNev;
	std::cout << "Adja meg az allomas nevet: " << std::endl;
	std::getline(std::cin, ujNev);
	std::cout << "Adja meg az erkezesi es indulasi idopontot(OO PP OO PP formatumban, az erkezessel kezdve): ";
	int eo, ep, io, ip;
	std::cin >> eo >> ep >> io >> ip;
	megallok.insert(Megallo(ujNev, Ido(eo, ep), Ido(io, ip)));
}

void Vonat::megalloTorol() {
	std::string ujNev;
	std::cout << "Adja meg a torolni kivant megallo nevet: ";
	std::getline(std::cin, ujNev);
	std::cout << std::endl;
	if (megallok[-1].getNev() == ujNev || megallok[0].getNev() == ujNev) {
		std::cout << "Vegallomas nem torolheto!" << std::endl;
		return;
	}
	for (size_t i = 0; i < megallok.len(); i++)
	{
		if (megallok[i].getNev() == ujNev) {
			megallok.torol(i);
			std::cout << "Megallo torolve!" << std::endl;
		}
	}
}


void Vonat::modosit()
{
	int valasztas = 0;
	while (valasztas != -1) {
		std::cout << "Mit szeretne modositani?\n\t1. Nev modositas\n\t2. Kocsi hozzaadasa\n\t3. Kocsi eltavolitasa\n\t4. Megallo hozzaadasa\n\t5 Megallo eltavolitasa" << std::endl;
		valasztas = beker(std::cin);
		std::string ujNev;
		switch (valasztas)
		{
		case 1:
			nevMod();
			break;
		case 2:
			kocsiFelvetel();
			break;
		case 3:
			kocsiTorol();
			break;
		case 4:
			megalloFelvetel();
			//std::cout << megallok;
			break;
		case 5:
			megalloTorol();
			break;
		default:
			break;
		}
		std::cout << "A modositott vonat: " << *this << std::endl;
	}
}

void Vonat::fajlba(std::ostream& os) const {
	os << id << ';' << nev << ';';
	keses.fajlba(os);
	os << "\n\n";
	for (size_t i = 0; i < kocsik.len(); i++)
	{
		kocsik[i].fajlba(os);
		os << "\n";
	}
	os << "\n";
	for (size_t i = 0; i < megallok.len(); i++)
	{
		megallok[i].fajlba(os);
		os << "\n";
	}
	os << "\n";
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
	std::string sor;
	std::getline(is, sor);
	std::stringstream ss(sor);
	std::string idStr, nevStr, kesesStr;

	std::getline(ss, idStr, ';');
	std::getline(ss, nevStr, ';');
	std::getline(ss, kesesStr);

	v.id = std::stoi(idStr);
	v.nev = nevStr;
	v.keses = Ido(kesesStr);

	std::getline(is, sor); // \n beolvas

	v.kocsik = DynArray<Kocsi>();
	while (std::getline(is, sor) && !sor.empty()) {
		std::stringstream kss(sor);
		std::string idS, feroS, kereS, bicajS;
		std::getline(kss, idS, ';');
		std::getline(kss, feroS, ';');
		std::getline(kss, kereS, ';');
		std::getline(kss, bicajS);

		int kid = std::stoi(idS);
		int fero = std::stoi(feroS);
		int kere = std::stoi(kereS);
		int bicaj = std::stoi(bicajS);
		v.kocsik += Kocsi(kid, fero, kere, bicaj);
	}



	v.megallok = DynArray<Megallo>();
	while (std::getline(is, sor) && !sor.empty()) {
		std::stringstream mss(sor);
		std::string nev, erk, ind;
		std::getline(mss, nev, ';');
		std::getline(mss, erk, ';');
		std::getline(mss, ind);

		Ido erkezes = erk != "-1 -1" ? Ido(erk) : Ido(-1, -1); // vagy Ido::ervenytelen()
		Ido indulas = ind != "-1 -1" ? Ido(ind) : Ido(-1, -1);
		v.megallok += Megallo(nev, erkezes, indulas);
	}
	return is;
}
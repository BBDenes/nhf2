#ifndef VONAT_H
#define VONAT_H

#include "memtrace.h"
#include "DynArray.hpp"
#include "ido.h"
#include "jegy.h"
#include "kocsi.h"
#include "megallo.h"

class Vonat {
	int id;
	std::string nev;
	DynArray<Kocsi> kocsik;
	DynArray<Megallo> megallok;
	Ido keses;

	//módosító privát függvények
	void nevMod();
	void kocsiFelvetel();
	void kocsiTorol();
	void megalloFelvetel();
	void megalloTorol();
public:
	//Default konstruktor, ha meg vannak adva a megállók, és a végállomás időpontja korábban van mint az indulás, std::invalid_argument kivételt dob
	Vonat(int id = 0, std::string n = "", DynArray<Kocsi> kocsik = DynArray<Kocsi>(), DynArray<Megallo> mg = DynArray<Megallo>(), Ido keses = Ido(0, 0));
	Vonat(const Vonat& rhs): id(rhs.id), nev(rhs.nev), kocsik(rhs.kocsik), megallok(rhs.megallok), keses(rhs.keses){}
	
	//@brief Statikus változó jegyID-k generálásához...
	static int jegyId;

	int getId() const;
	DynArray<Megallo>& getMegallok();
	DynArray<Kocsi>& getKocsik();


	/**
	 * @brief [] operátor.
	 * @param index A kocsi indexe.
	 * @return A kocsi referenciája.
	 */
	Kocsi& operator[](size_t index) const;


	/*
	* Vonatmódosító függvény. A konzolra adott bemenet alapján lehet választai, hogy mit szeretnénk módosítani
	*/
	void modosit();

	/*
	* Kiírja az ostreamre a vonat adatait
	* @param os: ostream, ahova ír
	*/
	void fajlba(std::ostream& os) const;

	/**
	 * @brief Beolvas egy vonat objektumot az input streamből.
	 * @param is Bemeneti stream.
	 * @param v A vonat, amelybe az adatokat beolvassuk.
	 * @return Az input stream referenciája.
	 */
	friend std::ostream& operator<<(std::ostream& os, Vonat& v);

	/**
	 * @brief Kiírja a vonat adatait az output streamre
	 * @param os Kimeneti stream.
	 * @param v A vonat objektum.
	 * @return A kimeneti stream referenciája.
	 */
	friend std::istream& operator>>(std::istream& is, Vonat& v);
};


#endif
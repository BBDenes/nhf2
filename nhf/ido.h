	#ifndef IDO_H
#define IDO_H
#include "memtrace.h"
#include<iostream>
#include <sstream>

class Ido {
private:
	int ora, perc;
public:

	//default konstruktor/konstruktor egész számokból
	Ido(int h = 0, int m = 0) : ora(h), perc(m) {}
	
	/**
	*	@brief Konstruktor egy stringből.A számokat MINDIG 2 számjeggyel kell megadni, szóközzel elválasztva
	*	(8 23 helyett 08 23)
	*/
	Ido(const std::string& ido);

	/*
	* @brief Másoló konstruktor. Nem több, nem kevesebb
	*/
	Ido(const Ido& i) : ora(i.ora), perc(i.perc) {}


	/**
	 * @brief Értékadó operátor.
	 * Lemásolja egy másik Ido objektum értékét az aktuális objektumba.
	 * @param i A másik Ido objektum.
	 * @return Az aktuális objektum referenciája.
	 */
	Ido& operator=(const Ido& i);

	/**
	 * @brief Összeadás operátor
	 * Két Ido objektumot ad össze
	 * @param i A másik Ido objektum.
	 * @return Az összeadás eredménye egy új Ido objektumban.
	 */
	Ido operator+(const Ido& i) const;

	/**
	 * @brief Kivonás operátor
	 * Két Ido objektum különbségét számítja ki
	 * @param i A kivonandó Ido objektum.
	 * @return Az eredmény egy új Ido objektumban.
	 */
	Ido operator-(const Ido& i) const;

	/**
	 * @brief Kisebb relációs operátor
	 * @param i A másik Ido objektum.
	 * @return true, ha az aktuális idő kisebb, különben false.
	 */
	bool operator<(const Ido& i) const;

	/**
	 * @brief Egyenlőségvizsgáló operátor.
	 * @param rhs A másik Ido objektum.
	 * @return true, ha egyenlőek, különben false.
	 */
	bool operator==(const Ido& rhs) const;

	int getOra() const;
	int getPerc() const;

	/**
	 * @brief Kiírja az időt fájlba.
	 * @param os Az output stream, ahová az adatot írja.
	 */
	void fajlba(std::ostream& os) const;


	/**
	 * @brief Kiíró operátor.
	 * @param os A kimeneti stream.
	 * @param ido Az Ido objektum, amit kiírunk.
	 * @return A módosított kimeneti stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Ido& ido);
};

#endif // !IDO_H

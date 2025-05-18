#ifndef PREDICATES_H
#define PREDICATES_H
#include "DynArray.hpp"
#include "memtrace.h"

/*
Csalóka nevű funktor, mindenre működik, aminek van getId() függvénye, igazat ad, ha talál a konstruktorában megadott id-t
*/
struct vonatId {
	vonatId(int i) : i(i) {}

	template<typename T>
	bool operator()(const T& x) {
		return x->getId() == i;
	}
private:
	int i;
};


/*
	Funktor, ami megadja, hogy két, a konstruktorában megadott megálló között "tudunk-e" utazni, azaz az adott 
	T(vonat) tartalmazza-e a két állomást, és a kiinduló állomás előbb van, mint az érkezési
*/
struct Allomasok {
	Allomasok(std::string n1, std::string n2) : elso(n1), masodik(n2) {}

	template<typename T>
	bool operator()(const T& x){
		int id1 = -1;
		int id2 = -1;
		for (int i = 0; i < int(x->getMegallok().len()); i++)
		{
			if (x->getMegallok()[i].getNev() == elso) {
				id1 = i;
			}
			if (x->getMegallok()[i].getNev() == masodik) {
				id2 = i;
			}
		}
		if (id1 == -1 || id2 == -1) return false;
		return id1 < id2;
	}

private:
	std::string elso, masodik;
};


#endif // !PREDICATES_H

#ifndef SEGEDFV_H
#define SEGEDFV_H
#include "memtrace.h"

//bekér egy számot a megadott istreamről, majd megpróbálja egész számmá konvertálni
//@param -is: az istream
//@return a szám, vagy nem megfelelő bemenet esetén -1
int beker(std::istream& is);

//generál egy véletlen egész számot a megadott keretek között (mindkét oldalon zárt intervallum)
//@param also: Alsó korlát
//@param felso: Felső korlát
int veletlenSzam(int also, int felso);

#endif
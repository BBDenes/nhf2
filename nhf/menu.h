#ifndef MENU_H
#define MENU_H
#include "memtrace.h"
#include "DynArray.hpp"
#include <iostream>
#include "vonat.h"

/*
* Függvény a menünek. Innen lehet a konzolra beírt parancsokkal kezelni a programot
* @param vonatok: a vonatok listája
*/
void fomenu(DynArray<Vonat>& vonatok);

/*
* Itt lehet kiválasztani, hogy milyen módosítási műveletet szeretnénk végrehajtani
* @param vonatok: a vonatok listája
*/
void kezeles(DynArray<Vonat>& vonatok);

#endif // !MENU_H


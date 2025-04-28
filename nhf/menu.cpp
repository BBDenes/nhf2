#include "menu.h"
#include "DynArray.hpp"
#include "kocsi.h"
#include "vonat.h"

void jegyvasarlas() {}

//bemenetek kezelésére @param maxInd: a maximum index ami még elfogadható
int beker(int maxInd) {
	int c;
	std::cin >> c;
	//input ellenőrzés
	return c;
}

void fomenu(DynArray<Vonat>& vonatok) {
	std::cout << "Fomenu - Valasztani a menupont sorszamaval lehet, kilepeshez -1\n"
		<< "\t1. Vonatjegy vasarlasa\n" << "\t2. Vonatok kezelese" << std::endl;
	int choice = beker(2);

	if (choice == -1)
	{
		exit(1);
	}
	else if (choice == 1) {
		jegyvasarlas();
	}
	else if (choice == 2) {
		vonatok.kezeles();
	}
}




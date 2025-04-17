#include <iostream>
#include "ido.h"
#include "megallo.h"


int main(void) {

	Ido i1(12, 21);
	Ido i2(13, 42);
	Ido i3;
	i3 = (i1 + i2) - i2; //02:03 - 13:42
	Ido i4(12, 21);

	std::cout << i3 << std::endl;
	std::cout << (i3 == i4) << std::endl;

	Megallo m1("Budapest-Keleti");

	std::cout << m1 << std::endl;

	Megallo m2("Budapest-Kelenfold", Ido(-1, -1), Ido(16, 14));
	std::cout << m2 << std::endl;

	return 0;
}
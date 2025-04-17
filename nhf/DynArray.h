#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <iostream>

template <typename T>
class DynArray {
	T** adat;
	size_t db;
public:
	//kiírja a lista tartalmát egy ostreamre (a kiir fuggvény helyett) @return os
	std::ostream& operator<<(std::ostream& os) {
		for (size_t i = 0; i < db; i++)
		{
			os << adat[i];
		}
		return os;
	}

	void operator+=(const T& rhs) {
		T* tmp = new T[db + 1];
		for (size_t i = 0; i < db; i++)
		{
			tmp[i] = adat[i];
		}
		tmp[db++] = rhs;
		delete[] adat;
		adat = tmp;
	}

	//törli a megadott indexű elemet a listából
	void torol(int index) {
		T* tmp = new T[db-1];
		for (size_t i = 0; i < db; i++)
		{
			if(i != index) 	tmp[i] = adat[i];

		}
		db--;
		delete[] adat;
		adat = tmp;
	}
};

#endif // !DYNARRAY_H

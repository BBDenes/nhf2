#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <iostream>
#include <fstream>

template <typename T>
class DynArray {
	T** adat;
	size_t db;
public:

	DynArray() : adat(nullptr), db(0) {}

	size_t len() { return db; }
	//kiírja a lista tartalmát egy ostreamre (a kiir fuggvény helyett) @return os
	std::ostream& operator<<(std::ostream& os) {
		for (size_t i = 0; i < db; i++)
		{
			os << *adat[i];
		}
		return os;
	}

	void operator+=(const T& rhs) {
		T** tmp = new T*[db + 1];
		for (size_t i = 0; i < db; i++)
		{
			tmp[i] = adat[i];
		}
		tmp[db] = new T(rhs);
		delete[] adat;
		adat = tmp;
		++db;
	}

	T& operator[](size_t i) const {
		return *adat[i];
	}

	//törli a megadott indexű elemet a listából @param A törölni kívánt index
	void torol(int index) {
		T* tmp = new T*[db-1];
		size_t uj_i = 0;
		for (size_t i = 0; i < db; i++) {
			if (i != index) {
				tmp[uj_i++] = adat[i];
			}
			else {
				delete adat[i];
			}
		}
		db--;
		delete[] adat;
		adat = tmp;
	}

	DynArray(const DynArray& other) : db(other.db) {
		adat = new T * [db];
		for (size_t i = 0; i < db; ++i) {
			adat[i] = new T(*other.adat[i]);
		}
	}

	DynArray& operator=(const DynArray& other) {
		if (this != &other) {
			clear();
			db = other.db;
			adat = new T * [db];
			for (size_t i = 0; i < db; ++i) {
				adat[i] = new T(*other.adat[i]);
			}
		}
		return *this;
	}

	bool includes(int id) {
		for (size_t i = 0; i < db; i++)
		{
			if (adat[i]->getId() == id) return true;
		}
		return false;
	}
	template<typename P>
	T& keres(P predicate) {
		for (size_t i = 0; i < db; i++)
		{
			if (predicate(adat[i])) {
				return *adat[i];
			}
		}
		throw std::exception;
	}

	void clear() {
		for (size_t i = 0; i < db; ++i) delete adat[i];
		delete[] adat;
	}

	~DynArray() {
		clear();
	}
};


#endif // !DYNARRAY_H

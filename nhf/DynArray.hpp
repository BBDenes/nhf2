#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class DynArray {
	T** adat;
	size_t db;
public:

	DynArray() : adat(nullptr), db(0) {}

	size_t len() { return db; }
	//kiírja a lista tartalmát egy ostreamre (a kiir fuggvény helyett) @return os
	friend std::ostream& operator<<(std::ostream& os, DynArray& da) {
		for (size_t i = 0; i < da.db; i++)
		{
			os << *(da.adat[i]);
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
		if (i == -1) return *adat[db - 1];
		return *adat[i];
	}

	//törli a megadott indexű elemet a listából @param A törölni kívánt index
	void torol(int index) {
		T** tmp = new T*[db-1];
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
		throw std::invalid_argument("Nincs ilyen!");
	}


	template<typename P>
	DynArray filter(P predicate) {
		DynArray uj;
		for (size_t i = 0; i < db; i++)
		{
			if (predicate(adat[i])) {
				uj += *adat[i];
			}
		}
		return uj;
	}

	void insert(const T& ujElem, size_t index = -1) {
		index == -1 ? index = db - 1 : index = index;
		if (index > db || index < 0) {
			throw std::out_of_range("Helytelen index!");
		}

		T** tmp = new T * [db + 1];

		
		for (size_t i = 0; i < index; ++i) {
			tmp[i] = adat[i];
		}
		tmp[index] = new T(ujElem);
		for (size_t i = index; i < db; ++i) {
			tmp[i + 1] = adat[i];
		}

		delete[] adat;
		adat = tmp;
		++db;
	}

	void clear() {
		for (size_t i = 0; i < db; ++i) delete adat[i];
		delete[] adat;
	}

	friend std::istream& operator>>(std::istream& is, DynArray& da) {
		int dbInt;
		try {
			std::string dbStr;
			std::getline(is, dbStr);
			std::cout << dbStr.c_str() << std::endl;
			dbInt = atoi(dbStr.c_str());

		}
		catch (std::exception& e) {
			std::cerr << "HIBA A vonatok szamanak beolvasasanal!: " << e.what() << std::endl;
			return is;
		}

		

		for (size_t i = 0; i < dbInt; ++i) {
			T obj;
			try
			{
				is >> obj;

			}
			catch (const std::exception& e)
			{
				std::cerr << "HIBA A(z) " << i << ". vonat beolvasasanal! " << e.what() << std::endl;
				throw std::exception("Fajlbeolvasas nem sikerult!");
				break;
			}
			da += obj;
		}
		return is;
	}

	~DynArray() {
		clear();
	}
};

template<typename T>
void adv_tokenizer(std::string str,DynArray<T>& arr, char del)
{
	std::stringstream stream(str);
	std::string word;
	while (!stream.eof()) {
		std::getline(stream, word, del);
		arr += 1;
	}
}





#endif // !DYNARRAY_H

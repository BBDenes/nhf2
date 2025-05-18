#ifndef DYNARRAY_H
#define DYNARRAY_H
#include "memtrace.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Sablonos dinamikus tomb implementacio.
 * @tparam T A tarolt objektum tipusa.
 */

template <typename T>
class DynArray {
	T** adat;
	size_t db;
public:

	/**
	 * @brief Konstruktor, ures tombot hoz letre.
	 */
	DynArray() : adat(nullptr), db(0) {}


	/**
	 * @brief Masolo konstruktor.
	 * @param other A masolando tomb.
	 */
	DynArray(const DynArray& other) : db(other.db) {
		adat = new T * [db];
		for (size_t i = 0; i < db; ++i) {
			adat[i] = new T(*other.adat[i]);
		}
	}
	
	
	/**
	 * @brief Visszaadja az elemek szamat.
	 * @return Az elemek szama.
	 */
	size_t len() const { return db; }


	/**
	 * @brief Kiirja az osszes elemet egy ostream-re.
	 * @param os A kimeneti ostream.
	 * @param da A kiirando tomb.
	 * @return Az ostream referenciakent.
	 */
	friend std::ostream& operator<<(std::ostream& os, DynArray& da) {
		for (size_t i = 0; i < da.db; i++)
		{
			os << *(da.adat[i]);
		}
		return os;
	}

	/**
	 * @brief Elem hozzadasa a tomb vegere.
	 * @param rhs A hozzáadni kívánt elem.
	 */
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

	//Iterátor kezdő pointer
	T** begin() {
		return adat;
	}

	//Iterátor vég pointer
	T** end() {
		return adat + db;
	}
	
	//Konstans iterátor kezdő pointer
	const T* const* begin() const {
		return adat;
	}

	//Konstans iterátor vég pointer
	const T* const* end() const {
		return adat + db;
	}


	//törli a megadott indexű elemet a listából @param ind: A törölni kívánt index
	void torol(size_t index) {
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


	/**
	 * @brief Ertekadasi operator.
	 * @param other A masik tomb.
	 * @return this
	 */
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

	/**
	 * @brief Indexeles operator. -1es indexre az utolsó elemet adja.
	 * @param i A kivant index.
	 * @return Referencia az adott indexu elemre.
	 */
	T& operator[](size_t i) const {
		if (i == (size_t)- 1) return *adat[db - 1];
		if (i >= db || i < 0) throw std::invalid_argument("Rossz index");
		return *adat[i];
	}

	/*
	* Megnézi, hogy a lista tartalmaz-e a megadott ID-vel adatot
	* @param id: A keresett id
	* @returns true, ha van, false ha nincs
	*/
	bool includes(int id) const {

		//for (size_t i = 0; i < db; i++) {
		//	if (adat[i]->getId() == id) return true;
		//}

		for (const T* v : *this) {
			if (v->getId() == id) return true;
		}

		return false;
	}

	//kereső függvény, ami a megadott prédikátum alapján megkeresi az első adatot, ami eleget tesz. Ha nincs ilyen, std::invalid_argument kivételt dob
	//@param predicate: A prédikátum
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

	/*
	* Prédikátumos szűrőfüggvény, ami a megadott prédikátum alapján kiszűri a megfelelő elemeket
	* @param predicate: prédikátum
	* @returns egy új DynArray, a szűrési feltételeknek megfelelő elemekkel
	*/
	template<typename P>
	DynArray filter(P predicate) const {
		DynArray uj;
		for (size_t i = 0; i < db; i++)
		{
			if (predicate(adat[i])) {
				uj += *adat[i];
			}
		}
		return uj;
	}

	/*
	* Beszúr egy elemet a megadott indexre. Amennyiben nincs megadva, úgy az utolsó előtti helyre szúrja be
	* @param ujElem: az új elem (T)
	* @param index: beszúrási index
	*/
	void insert(const T& ujElem, int index = -1) {
		index == -1 ? index = int(db) - 1 : index = index;
		int(db) == 0 ? index = 0 : index = index;
		if (index > int(db) || index < 0) {
			throw std::out_of_range("Helytelen index!");
		}

		T** tmp = new T * [db + 1];

		
		for (int i = 0; i < index; ++i) {
			tmp[i] = adat[i];
		}
		tmp[index] = new T(ujElem);
		for (int i = index; i < (int)db; ++i) {
			tmp[i + 1] = adat[i];
		}

		delete[] adat;
		adat = tmp;
		++db;
	}

	/*
	* Felszabadítja a lista elemeit
	*/
	void clear() {
		for (size_t i = 0; i < db; ++i) delete adat[i];
		delete[] adat;
	}


	/*
	* A megadott nevű fájlból beolvassa az adatokat. Ha nem sikerül megnyitni a fájlt, std::runtime_error kivételt,
	* ha a fájlbeolvasás közben történik probléma, std::exception kivételt dob.
	* @param fajlnev: A fájl neve
	* 
	*/
	void fajlbol(const char* fajlnev) {
		std::ifstream f(fajlnev);
		if (!f) throw std::runtime_error("Nem sikerult megnyitni a fajlt!");
		try
		{
			f >> *this;
		}
		catch (const std::exception&)
		{
			throw std::runtime_error("fajlhiba");
		}
		f.close();
	}

	/*
	* Kiírja a megadott nevű fájlba az adatokat
	* Ha nem sikerül megnyitni a fájlt, std::runtime_error kivételt dob
	* @param fajlnev: A fájl neve
	*/
	void fajlba(const char* fajlnev) const {
		std::ofstream f(fajlnev);
		if (!f) throw std::runtime_error("Nem sikerult megnyitni a fajlt!");
		f << db << '\n';
		for (const T* x : *this)
		{
			x->fajlba(f);
		}
		
	}

	
	friend std::istream& operator>>(std::istream& is, DynArray& da) {
		int dbInt;
		try {
			std::string dbStr;
			std::getline(is, dbStr);
			dbInt = atoi(dbStr.c_str());

		}
		catch (std::exception& e) {
			std::cout << "HIBA A vonatok szamanak beolvasasanal!: " << e.what() << std::endl;
			return is;
		}

		

		for (int i = 0; i < dbInt; ++i) {
			T obj;
			try
			{
				is >> obj;

			}
			catch (const std::exception& e)
			{
				std::cout << "HIBA A(z) " << i << ". vonat beolvasasanal! " << e.what() << std::endl;
				throw std::runtime_error("Fajlbeolvasas nem sikerult!");
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
#endif // !DYNARRAY_H
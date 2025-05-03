#ifndef PREDICATES_H
#define PREDICATES_H

struct vonatId {
	vonatId(int i) : i(i) {}

	template<typename T>
	bool operator()(const T& x) {
		return x->getId() == i;
	}
private:
	int i;
};

struct Indulas {
	Indulas(std::string nev): str(nev){}

	template<typename T>
	bool operator()(const T& x) {
		return x.getMegallok()[0].getNev() == str;
	}
private:
	std::string str;
};




#endif // !PREDICATES_H

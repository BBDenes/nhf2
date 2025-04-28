#include "ido.h"


Ido& Ido::operator=(const Ido& i) {
	if (this != &i) {
		ora = i.ora;
		perc = i.perc;
	}
	return *this;
}
Ido Ido::operator+(const Ido& i) const {
	Ido result;
	result.ora = ora + i.ora;
	if (ora + i.ora >= 24) {
		result.ora -= 24;
	}
	result.perc = perc + i.perc;
	if (perc + i.perc >= 60) {
		result.perc -= 60;
		result.ora++;
	}
	return result;
}
Ido Ido::operator-(const Ido& i) const {
	Ido result;
	result.perc = perc - i.perc;
	result.ora = ora - i.ora;
	if (result.ora < 0) result.ora = 24 + result.ora;
	if (result.perc < 0) {
		result.perc += 60;
		result.ora--;
	}
	return result;
}


int Ido::getOra() const { return ora; }
int Ido::getPerc() const { return perc; }
Ido Ido::get() const { return *this; }
bool Ido::operator==(const Ido& rhs) const {
	return (this->perc == rhs.perc && this->ora == rhs.ora);
}
#include "ido.h"
#include <iomanip>


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

bool Ido::operator<(const Ido& i) const{
	if (ora != -1 && perc != -1 && i.ora != -1 && i.perc != -1) {
		if (ora != i.ora)
			return ora < i.ora;
		return perc < i.perc;
	}
	return false;
}


int Ido::getOra() const { return ora; }
int Ido::getPerc() const { return perc; }
bool Ido::operator==(const Ido& rhs) const {
	return (this->perc == rhs.perc && this->ora == rhs.ora);
}

std::ostream& operator<<(std::ostream& os, const Ido& ido) {
	os << std::setw(2) << std::setfill('0') << ido.ora << ":" << std::setw(2) << std::setfill('0') << ido.perc;
	return os;
}
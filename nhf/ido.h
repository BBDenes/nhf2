#ifndef IDO_H
#define IDO_H
#include<iostream>

class Ido {
private:
	int ora, perc;
public:
	Ido(int h = 0, int m = 0) : ora(h), perc(m) {
		
	}
	Ido(const Ido& i) : ora(i.ora), perc(i.perc) {}
	Ido& operator=(const Ido& i) {
		if (this != &i) {
			ora = i.ora;
			perc = i.perc;
		}
		return *this;
	}
	Ido operator+(const Ido& i) const {
		Ido result;
		result.ora = ora + i.ora;
		if (ora + i.ora >= 24) {
			result.ora-= 24;
		}
		result.perc = perc + i.perc;
		if (perc + i.perc >= 60) {
			result.perc -= 60;
			result.ora++;
		}
		return result;
	}
	Ido operator-(const Ido& i) const {
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
	

	int getOra() const { return ora; }
	int getPerc() const { return perc; }
	Ido get() const { return *this; }
	bool operator==(const Ido& rhs) const {
		return (this->perc == rhs.perc && this->ora == rhs.ora);
	}

};

std::ostream& operator<<(std::ostream& os, Ido rhs) {
	os << rhs.getOra() << ":" << rhs.getPerc();
	return os;
}

#endif // !IDO_H


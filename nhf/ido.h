#ifndef IDO_H
#define IDO_H
#include<iostream>
#include <sstream>

class Ido {
private:
	int ora, perc;
public:
	Ido(int h = 0, int m = 0) : ora(h), perc(m) {}
	Ido(const std::string& ido) {
		std::string oraStr = ido.substr(0, 2);
		std::string percStr = ido.substr(3, 2);
		ora = std::stoi(oraStr);
		perc = std::stoi(percStr);
	}
	Ido(const Ido& i) : ora(i.ora), perc(i.perc) {}

	

	Ido& operator=(const Ido& i);
	Ido operator+(const Ido& i) const;
	Ido operator-(const Ido& i) const;
	bool operator<(const Ido& i) const;

	int getOra() const;
	int getPerc() const;
	bool operator==(const Ido& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Ido& ido);
};

#endif // !IDO_H

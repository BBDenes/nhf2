#ifndef IDO_H
#define IDO_H
#include<iostream>

class Ido {
private:
	int ora, perc;
public:
	Ido(int h = 0, int m = 0) : ora(h), perc(m) {}
	Ido(const Ido& i) : ora(i.ora), perc(i.perc) {}
	

	Ido& operator=(const Ido& i);
	Ido operator+(const Ido& i) const;
	Ido operator-(const Ido& i) const;

	int getOra() const;
	int getPerc() const;
	Ido get() const;
	bool operator==(const Ido& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Ido& ido);
};

#endif // !IDO_H

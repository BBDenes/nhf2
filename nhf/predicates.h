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




#endif // !PREDICATES_H

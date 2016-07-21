
#ifndef INTSET_H
#define INTSET_H

#include "intsetbase.h"

const int MAXELTS=100;

intsetbase *getintset();

class intset: public intsetbase{
	int elts[MAXELTS];
	int numElts;

public:
	intset();
	int indexOf(int v) const;
	void insert(int v);
	void remove(int v);
	bool query(int v) const;
	int size() const;






};







#endif
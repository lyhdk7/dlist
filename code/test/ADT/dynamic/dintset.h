#ifndef DYNAMICINTSET_H
#define DYNAMICINTSET_H

const int MAX=100;


class dintset{

	int *elt;
	int sizeelt;
	int numelt;

	void copyFrom(const dintset &is);
public:

	dintset(int x=MAX);
	bool isEmpty();
	int indexOf(int v);
	void insert(int v);
	void remove(int v);
	bool query(int v);
	int size();

	dintset(const dintset &is);
	dintset &operator=(const dintset &is);

	~dintset();


};





#endif
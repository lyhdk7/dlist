#include <iostream>
#include "dintset.h"

using namespace std;


dintset::dintset(int x)
{
	elt=new int[x];
	sizeelt=x;
	numelt=0;
}

dintset::~dintset()
{
	delete[] elt;
}


bool dintset::isEmpty()
{
	return numelt==0;
}

int dintset::size()
{
	return numelt;
}

int dintset::indexOf(int v) 
{
	for (int i=0; i<numelt; i++)
	{
		if (*(elt+i)==v) return i;
	}
	return sizeelt;
}


void dintset::insert(int v)
{
	if (indexOf(v)==sizeelt&&numelt<sizeelt)
	{
		*(elt+numelt)=v;
		numelt++;
	}
	else
	{
		cout<<"fail"<<endl;
	}
}

void dintset::remove(int v)
{
	int vic=indexOf(v);
	*(elt+vic-1)==*(elt+numelt-1);
	numelt--;
}

bool dintset::query(int v)
{
	return indexOf(v)!=sizeelt;
}



void dintset::copyFrom(const dintset &is)
{
	if (is.sizeelt!=sizeelt)
	{
		delete[] elt;
		elt=new int[is.sizeelt];
	}
	sizeelt=is.sizeelt;
	numelt=is.numelt;
	for (int i=0; i<sizeelt; i++)
	{
		*(elt+i)=is.elt[i];
	}

}





dintset::dintset(const dintset &is)
{
	elt=NULL;
	numelt=0;
	sizeelt=0;
	copyFrom(is);
}



dintset &dintset::operator=(const dintset &is)
{
	copyFrom(is);
	return *this;
}



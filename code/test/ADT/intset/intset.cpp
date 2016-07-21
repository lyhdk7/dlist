#include <iostream>
#include "intset.h"
using namespace std;

static intset impl;

intsetbase *getintset()
{
	return &impl;
}


int intset::size() const
{
	return numElts;
}

int intset::indexOf(int v) const
{
	for (int i=0;i<numElts;i++)
	{
		if (elts[i]==v)
		{
			return i;
		}
	}
	return MAXELTS;
}

bool intset::query(int v) const
{
	return (indexOf(v)!=MAXELTS);
}

void intset::insert(int v)
{
	if (indexOf(v)==MAXELTS)
	{
		if (numElts==MAXELTS) throw MAXELTS;
		elts[numElts++]=v;
	}


}




void intset::remove(int v)
{
	int victim=indexOf(v);
	if (victim!=MAXELTS)
	{	
		numElts--;
		while (victim<numElts)
		{
			elts[victim]=elts[victim+1];
			victim++;
		}
	}
}

intset::intset():numElts(0)
{

}


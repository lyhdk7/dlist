#include <iostream>
#include "intset.h"
#include "intsetbase.h"
using namespace std;

int main()
{
	intsetbase *a=getintset();
	a->insert(5);
	a->insert(3);
	a->insert(1);
	cout<<a->size()<<endl;
	return 0;
}
#include <iostream>
#include "list_t.h"

using namespace std;

int main()
{
	list_t a;
	a.insert(5);
	a.insert(4);
	a.insert(3);
	a.insert(2);
	list_t b;
	
	//list_t b(a);
	//a.print();
	b.print();
	return 0;
}
#include <iostream>
#include "p2.h"

using namespace std;

int main()
{
	
	list_t test;
	test=list_make(5,list_make());
	test=chop(test,1);
	list_print(test);








	return 0;
}


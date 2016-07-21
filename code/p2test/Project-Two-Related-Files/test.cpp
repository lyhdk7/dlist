#include<iostream>
#include<cstdlib>
#include"p2.h"
#include"recursive.h"

using namespace std;

int main()
{
	list_t list1=list_make();
	list1=list_make(1,list1);
	list1=list_make(2,list1);
	list1=list_make(3,list1);
	list1=list_make(4,list1);
	list1=list_make(5,list1);
	list1=list_make(6,list1);
	list1=list_make(7,list1);
	list_print(list1);
	list1=chop(list1,2);
	list_print(list1);
	return 0;
}
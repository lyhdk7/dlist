#include <iostream>
#include "dlist.h"

using namespace std;

int main()
{
	Dlist<int> a;


	int *a1=new int(1);
	int *a2=new int(2);
	int *a3=new int(3);
	int *a4=new int(4);
	//cout<<a.isEmpty()<<endl;
	a.insertFront(a1);
	//cout<<"123"<<endl;
	//a.removeFront();
	//cout<<"success"<<endl;
	a.insertFront(a2);
	a.insertBack(a3);
	a.insertBack(a4);
/*
	int *leak;
	leak=a.removeBack();

	cout<<*leak<<endl;
	delete leak;
	
*/

	Dlist<int> b(a);
	//b=a;


	Dlist<int> c(a);

	int *p=c.removeFront();

	cout<<*p<<endl;
	delete p;

	//b.print();

	return 0;

}
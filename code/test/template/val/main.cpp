#include <iostream>

#include "template.cpp"

using namespace std;

int main()
{

	list_t<double> a;
	a.insert(5.3);
	a.insert(4);
	a.insert(3);
	a.insert(2);

	list_t<double> c;
	c.insert(3);

	c=a;


	c.print();
	cout<<endl;

	return 0;

}
#include <iostream>

#include "temptr.cpp"

using namespace std;

int main()
{
	double *first = new double(3.5);
	double *second = new double(2.5);
	double *third = new double(1.5);
	list_t<double> a;
	a.insert(third);
	a.insert(second);
	a.insert(first);
	double *leak;
	leak=a.remove();
	delete leak;
	list_t<double> b;
	b=a;

	b.print();

	return 0;

}
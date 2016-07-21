#include<iostream>
using namespace std;

int main()
{
	int b=11;
	int ab=12;
	typedef  int* ptr;
	typedef const ptr ptr_con_int;

	ptr_con_int a=&b;
	a=&ab;
	*a=12;

	cout<<*a<<endl;




}
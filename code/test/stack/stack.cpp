#include<iostream>
using namespace std;

void test(int *p);

int main()
{
	int a=10;
	int *p=&a;
	cout<<*p<<endl;
	test(p);
	cout<<*p<<endl;
	return 0;
}

void test(int *p)
{
	int b=2;
	p=&b;
	cout<<*p<<endl;
	
}


#include<iostream>
using namespace std;
void change(int *a);

int main()
{
	int b=1;
	int *a=&b;
	change(&b);
	cout<<b<<endl;
	return 0;

}

void change(int *a)
{
	*a=2;
}

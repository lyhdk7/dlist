#include<iostream>
using namespace std;

int factorial(int n);

int main()
{
	int a;
	cout<<"please enter the number: ";
	cin>>a;
	int result;
	result=factorial(a);
	cout<<"the result is "<<result<<endl;
	return 0;

}

int factorial(int n)
{
	if (n==0)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}


}
#include<iostream>
using namespace std;

int main()
{
	int  ival=1024;
	int &refval=ival;
	int ival2=10;
	refval=ival2;
	cout<<ival<<" "<<refval<<endl;
	return 0;
	
}



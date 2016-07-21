#include<iostream>
#include<string>
using namespace std;

int main()
{
	string test1;

	test1="hello";


	
	string output;




	for (int i=0;i<5;i++)
	{
		output.push_back(test1[4-i]);
	}
	cout<<output<<endl;
	return 0;
}
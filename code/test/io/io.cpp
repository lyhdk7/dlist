#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream oFile1;
	oFile1.open("test.txt");

	oFile1<<"hello"<<endl;
	oFile1.close();
	return 0;



}
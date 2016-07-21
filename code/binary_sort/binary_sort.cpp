#include<iostream>
using namespace std;

int sort(int v, int k[]);

int main()
{
	int result;
	int k[6];
	k[0]=1;
	k[1]=3;
	k[2]=5;
	k[3]=7;
	k[4]=8;
	k[5]=9;
	k[6]=11;
	k[7]=14;

	result=sort(14, k);
	cout<<result<<endl;
	return 0;
}


int sort(int v, int k[])
{
	int size=8;
	int left=0;
	int right=size-1;
	int medium=(left+right)/2;

	while(left<=right)
	{
		if (k[medium]==v) return medium;
		else if (k[medium]>v)
		{
			right=medium-1;
			medium=(left+right)/2;
		}
		else 
		{
			left=medium+1;
			medium=(left+right)/2;
		}
	}
	return -1;




}
#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int i;
	int j;
	for (i=2;i<argc;i++)
	{
		j=atoi(argv[i]);
		char *sample[1];
		sample[0]=argv[i];
		int k=1;
		int m;
		while (j<atoi(argv[k]))
		{
			k++;
		}
		for (m=i-1;m>k-1;m--)
		{
			argv[m+1]=argv[m];
		}
		argv[k]=sample[0];

	}
	for (i=1;i<argc;i++)
	{
		cout<<argv[i]<<" ";
	}
	cout<<endl;
	
}
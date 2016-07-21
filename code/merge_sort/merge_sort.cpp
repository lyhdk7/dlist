#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;

void merge(int *A, int p, int q, int r);
void mergesort(int *A, int left, int right);
int main(int argc, char *argv[])
{

	int A[argc-1];
	for (int i=0; i<argc-1; i++)
	{
		A[i]=atoi(argv[i+1]);
	}
	mergesort(A, 0, argc-2);
	for (int i=0; i<argc-1; i++)
	{
		cout<<A[i];
	}
	cout<<endl;
	return 0;




}


void merge(int *A, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = p;
	int B[100];
	while (i <= q && j <= r)
	{
		if (A[i]<A[j])
		{
			B[k] = A[i];
			k++;
			i++;
		}
		else
		{
			B[k] = A[j];
			k++;
			j++;

		}

	}
	if (i > q)
	{
		for (int h = j; h <= r; h++)
		{
			B[k] = A[h];
			k++;
		
		}
	}
	else
	{
		for (int h = i; h <= q; h++)
		{
			B[k] = A[h];
			k++;

		}
	}
	


	int g;
	for (g = p; g<=r; g++)
	{
		A[g] = B[g];
	}

}

void mergesort(int *A, int left, int right)
{
	if (left<right)
	{
		int i = (left + right) / 2;
		mergesort(A, left, i);
		mergesort(A, i + 1, right);
		merge(A, left, i, right);
	}
}
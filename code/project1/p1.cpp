#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;

bool function1(int a); //judge whether it is a triangle number

bool function2(int a); //judge whether it is a palidrome number

bool function3(int a); //judge whether it is a power number

bool function4(int a); //judge whether it is a adundunt number



int main()
{
	int i;
	int j;
	int a;
	int b;
	cout<<"Please enter the integer and the test number: ";
	cin>>a>>b;

	while (a<1||a>10000000||b>4||b<1) //judge whether the input is valid
	{
	cout<<"Please enter the integer and the test number: ";
	cin>>a>>b;
	}
	
	int integer_number=a;
	int test_number=b;

	int bool_number;

	if (test_number==1)
	{
		bool_number=function1(integer_number);
	}
	else if (test_number==2)
	{
		bool_number=function2(integer_number);
	}
	else if (test_number==3)
	{
		bool_number=function3(integer_number);
	}
	else
	{
		bool_number=function4(integer_number);
	}

	cout<<bool_number<<endl;
	return 0;

}

bool function1(int a)
{
	int i=1;
	while (i*(i+1)/2<a)      //stop when it is larger than or equal to a
	{
		i++;
	}
	return (i*(i+1)/2==a);  //judge whether it is equal to a
}

bool function2(int a)
{
	int a_ch[100];
	int length_a=1;
	int a_1=a;
	int a_2=a;
	while (a_1/10>0)    //get the length of a
	{
		length_a++;
		a_1=a_1/10;
	}
	int j;
	for (j=1;j<=length_a;j++)   //put a into a array
	{
		a_ch[length_a-j]=a_2%10;
		a_2=a_2/10;
	}



	int length=length_a;  


	int i;
	int bool_fake=1;
	for (i=0;i<length;i++) //judge whether it is a palindrome number
	{
		if (a_ch[i]!=a_ch[length-i-1])
		{
			bool_fake=0;
			break;
		}
	}

	return bool_fake;

}


bool function3(int a)
{
	int m=1;
	int n=1;

	int bool_number=0;
	if (a==1)
	{
		return 1;
	}
	else
	{
		for (m=1;m<a;m++)
		{
			for (n=2;n<=a;n++)
			{
				if (pow(m,n)>=a) //when it is larger than or equal to a, stop
				{
					if (pow(m,n)==a)
					{
						bool_number=1;
					}
					break; //enumeration for n is over, increase m to start a new  enumeration
				}
			}
				

		}
		return bool_number;
	
	}
}



bool function4(int a)
{
	int i=0;
	int number[100];
	int k=0;
	for (i=1;i<a;i++) //put its all proper divisors into an array
	{
		if (a%i==0)
		{
			number[k]=i;
			k++;

		}
	}


	int m;
	int sum=0;

	for (m=0;m<k;m++) //get the sum of the array
	{
		sum=sum+number[m];
	}

	if (sum>a) //judge whether it is an abundant number
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

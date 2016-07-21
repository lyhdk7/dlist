#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "dlist.h"

using namespace std;

int getOpNum(string input);

int main()
{
	string input;
	cin>>input;

	Dlist<int> stack_calc;

	int op_num=getOpNum(input);


	while (op_num!=11)
	{
		try
		{
			//cout<<op_num<<endl;
			if (op_num==-1) cout<<"Bad input\n";
			else if (op_num==0)
			{
				int val=atoi(input.c_str());
				int *num_in=new int(val);
				stack_calc.insertFront(num_in);
			}

			else if (op_num==1)
			{
				//cout<<"success"<<endl;
				int *num1=stack_calc.removeFront();
				if (stack_calc.isEmpty()==1) 
				{
					cout<<"Not enough operands\n";
					stack_calc.insertFront(num1);
				}
				else
				{
					int *num2=stack_calc.removeFront();
					int *push=new int(*num1+*num2);
					stack_calc.insertFront(push);
					delete num1;
					delete num2;

				}
				
			}
			else if (op_num==2)
			{
				//cout<<"success"<<endl;
				int *num1=stack_calc.removeFront();
				if (stack_calc.isEmpty()==1) 
				{
					cout<<"Not enough operands\n";
					stack_calc.insertFront(num1);
				}
				else
				{
					int *num2=stack_calc.removeFront();
					//cout<<"success"<<endl;
					int *push=new int(*num2-*num1);
					stack_calc.insertFront(push);
					delete num1;
					delete num2;
				}	
			}
			else if (op_num==3)
			{
				int *num1=stack_calc.removeFront();
				if (stack_calc.isEmpty()==1) 
				{
					cout<<"Not enough operands\n";
					stack_calc.insertFront(num1);
				}
				else
				{
					int *num2=stack_calc.removeFront();
					int *push=new int((*num2)*(*num1));
					stack_calc.insertFront(push);
					delete num1;
					delete num2;
				}
			}
			else if (op_num==4)
			{
				int *num1=stack_calc.removeFront();
				if (stack_calc.isEmpty()==1) 
				{
					cout<<"Not enough operands\n";
					stack_calc.insertFront(num1);
				}
				else if (*num1==0)
				{
					cout<<"Divide by zero\n";
					stack_calc.insertFront(num1);
				}
				else
				{
					int *num2=stack_calc.removeFront();
					int *push=new int((*num2)/(*num1));
					stack_calc.insertFront(push);
					delete num1;
					delete num2;
				}	
			}
			else if (op_num==5)
			{
				int *num1=stack_calc.removeFront();
				*num1=-*num1;
				stack_calc.insertFront(num1);
			}
			else if (op_num==6)
			{
				int *num1=stack_calc.removeFront();
				int *num2=new int(*num1);
				stack_calc.insertFront(num1);
				stack_calc.insertFront(num2);
			}
			else if (op_num==7)
			{
				int *num1=stack_calc.removeFront();
				if (stack_calc.isEmpty()==1) 
				{
					cout<<"Not enough operands\n";
					stack_calc.insertFront(num1);
				}
				else
				{
					int *num2=stack_calc.removeFront();
					stack_calc.insertFront(num1);
					stack_calc.insertFront(num2);
				}
			}
			else if (op_num==8)
			{
				int *num1=stack_calc.removeFront();
				cout<<*num1<<endl;
				stack_calc.insertFront(num1);
			}
			else if (op_num==9)
			{
				while(!stack_calc.isEmpty())
				{
					int *num1=stack_calc.removeFront();
					delete num1;
				}
			}
			else if (op_num==10)
			{
				Dlist<int> stack_help;
				while(!stack_calc.isEmpty())
				{
					int *num1=stack_calc.removeFront();
					stack_help.insertBack(num1);
					cout<<*num1<<" ";
				}
				cout<<endl;
				while(!stack_help.isEmpty())
				{
					int *num1=stack_help.removeFront();
					stack_calc.insertBack(num1);
				}
			}
			
		


		}
		catch(emptyList e)
		{
			cout<<"Not enough operands\n";
		}


		cin>>input;
		op_num=getOpNum(input);
	}


	return 0;

}

int getOpNum(string input)
{

	int num_flag=1;

	int str_size=input.size();
	if ((input[0]<48||input[0]>57)&&input[0]!=45||input[0]==45&&str_size==1) num_flag=0;

	for (int i=1;i<str_size;++i)
	{
		if (input[i]<48||input[i]>57) num_flag=0;
	}

	if (num_flag==1) return 0;




	if (input=="+") return 1;
	else if (input=="-") return 2;
	else if (input=="*") return 3;
	else if (input=="/") return 4;
	else if (input=="n") return 5;
	else if (input=="d") return 6;
	else if (input=="r") return 7;
	else if (input=="p") return 8;
	else if (input=="c") return 9;
	else if (input=="a") return 10;
	else if (input=="q") return 11;
	else return -1;
}
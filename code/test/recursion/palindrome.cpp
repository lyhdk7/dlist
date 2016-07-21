#include<iostream>
#include<string>
using namespace std;

bool is_palindrome(string s);

bool is_palindrome_helper(string s, int position, int length);

int main()
{
	bool result;
	string s;
	cout<<"please in put a string ";
	cin>>s;
	result=is_palindrome(s);
	cout<<result<<endl;
	return 0;

}

bool is_palindrome(string s)
{
	bool result;
	int length=s.length();
	result=is_palindrome_helper(s,0, length);
	return result;
}

bool is_palindrome_helper(string s, int position, int length)
{
	if (position==length)
	{
		return 1;
	}
	else
	{

		if (s.at(position)==s.at(length-1-position))
		{
			return is_palindrome_helper(s,position+1,length);
		}
		else
		{
			return 0;
		}
	}
}
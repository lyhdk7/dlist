#include <iostream>
#include "dintset.h"

using namespace std;


void foo(dintset s);

int main()
{
	dintset set(4);

	dintset set1;

	set.insert(5);
	//cout<<set.indexOf(5)<<endl;
	set1=set;
	foo(set);

	cout<<set1.query(5)<<endl;

	return 0;

}

void foo(dintset s)
{
	//cout<<s.query(5)<<endl;
}
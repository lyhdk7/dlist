#include<iostream>
#include<cstdlib>
#include"p2.h"
#include"recursive.h"

using namespace std;


list_t chop_helper(list_t list, int *k, unsigned int n);

list_t chop(list_t list, unsigned int n)
{
	int a=1;
	int *k;
	k=&a;
	return chop_helper(list,k,n);
}

list_t chop_helper(list_t list, int *k, unsigned int n)
{
	if (list_isEmpty(list)==1)
	{
		*k=1;
		return list_make();
	}
	else
	{
		list_t list_help;
		list_help=chop_helper(list_rest(list),k,n);
		if (*k<=n)
		{
			*k=*k+1;
			return list_make();
		}
		else
		{
			return list_make(list_first(list),list_help);
		}
	}
}
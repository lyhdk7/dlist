#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "hand.h"
using namespace std;



Hand::Hand()
{
	HandValue helper;
	helper.count=0;
	helper.soft=0;
	curValue=helper;

}

void Hand::discardAll()
{
	curValue.count=0;
	curValue.soft=0;
}

void Hand::addCard(Card c)
{
	int num_spot=int(c.spot);
	if (num_spot<=8)
	{
		if (curValue.soft==0)
		{
			curValue.count=curValue.count+num_spot+2;
		}
		else
		{
			int instant_value=curValue.count+num_spot+2;
			if (instant_value>21)
			{
				curValue.count=instant_value-10;
				curValue.soft=0;
			}
			else
			{
				curValue.count=instant_value;
			}
		}
		
	}
	else if (num_spot!=12)
	{
		if (curValue.soft==0)
		{
			curValue.count=curValue.count+10;
		}
		else
		{
			int instant_value=curValue.count+10;
			if (instant_value>21)
			{
				curValue.count=instant_value-10;
				curValue.soft=0;
			}
			else
			{
				curValue.count=instant_value;
			}
		}
		
	}
	else
	{
		if (curValue.soft==1)
		{
			int instant_value=curValue.count+1;
			if (instant_value>21)
			{
				curValue.count=instant_value-10;
				curValue.soft=0;
			}
			else
			{
				curValue.count=instant_value;
			}

		}
		else
		{
			int instant_value=curValue.count+11;
			if (instant_value>21)
			{
				curValue.count=instant_value-10;

			}
			else
			{
				curValue.count=instant_value;
				curValue.soft=1;
			}
		}
		
	}
}

HandValue Hand::handValue() const
{
	return curValue;
}
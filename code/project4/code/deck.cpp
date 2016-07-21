#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "deck.h"
using namespace std;

Deck::Deck()
{
	for (int i=0; i<52; i++)
	{
		int spot_num=i%13;
		int suit_num=i/13;
		Card card_input;
		card_input.spot=Spot(spot_num);
		card_input.suit=Suit(suit_num);
		deck[i]=card_input;
	}

	next=0;
}

void Deck::reset()
{
	for (int i=0; i<52; i++)
	{
		int spot_num=i%13;
		int suit_num=i/13;
		Card card_input;
		card_input.spot=Spot(spot_num);
		card_input.suit=Suit(suit_num);
		deck[i]=card_input;
	}
	next=0;
}

void Deck::shuffle(int n)
{
	int num_left=n;
	int num_right=52-n;

	Card deck_left[num_left];
	Card deck_right[num_right];


	for (int i=0;i<num_left;i++)
	{
		deck_left[i]=deck[i];
	}

	for (int i=0; i<num_right; i++)
	{
		deck_right[i]=deck[num_left+i];
	}

	if (num_right>=num_left)
	{
		for (int i=0; i<2*num_left; i++)
		{
			int pos=i/2;
			if (i%2==0) deck[i]=deck_right[pos];
			else deck[i]=deck_left[pos];
		}
		for (int i=2*num_left; i<52; i++)
		{
			deck[i]=deck_right[i-52+num_right];
		}
	}
	else
	{
		for (int i=0; i<2*num_right; i++)
		{
			int pos=i/2;
			if (i%2==0) deck[i]=deck_right[pos];
			else deck[i]=deck_left[pos];
		}
		for (int i=2*num_right; i<52; i++)
		{
			deck[i]=deck_left[i-52+num_left];
		}
	}

	next=0;
}

Card Deck::deal()
{
	DeckEmpty exception;
	if (next>=52) throw exception;
	else
	{	
		next++;
		return deck[next-1];
	}
}

int Deck::cardsLeft()
{
	return 52-next;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "player.h"
using namespace std;

extern Player *get_Simple();
extern Player *get_Counting();



class Simple_Player:public Player{
	//Card card_exposed[DeckSize];
	//int num_card_exposed;
	//bool card_shuffled;

public:
	//Simple_Player();

	int bet(unsigned int bankroll,unsigned int minimum);

	bool draw(Card dealer, const Hand &player);

	void expose(Card c);

	void shuffled();

};

void Simple_Player::expose(Card c)
{}

void Simple_Player::shuffled()
{}


int Simple_Player::bet(unsigned int bankroll, unsigned int minimum)
{
	return minimum;
}

bool Simple_Player::draw(Card dealer, const Hand &player)
{
	HandValue hand_player=player.handValue();
	if (hand_player.soft==0)
	{
		if (hand_player.count<=11)
		{
			return 1;
		}
		else if (hand_player.count==12)
		{
			if (int(dealer.spot)==2||int(dealer.spot)==3||int(dealer.spot)==4)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if (hand_player.count>=13&&hand_player.count<=16)
		{
			if (int(dealer.spot)<=4&&int(dealer.spot)>=0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (hand_player.count<=17) return 1;
		else if (hand_player.count==18)
		{
			if (int(dealer.spot)==0||int(dealer.spot)==5||int(dealer.spot)==6)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}

/*

void Simple_Player::expose(Card c)
{
	card_exposed[num_card_exposed]=c;
	num_card_exposed++;
}

void Simple_Player::shuffled()
{
	card_shuffled=1;
}

*/

class Counting_Player:public Simple_Player{


	int player_count;
public:

	Counting_Player();

	int bet(unsigned int bankroll,unsigned int minimum);

	void expose(Card c);

	void shuffled();

	//int showcount();
};

/*
int Counting_Player::showcount()
{
	return player_count; 
}
*/
Counting_Player::Counting_Player():player_count(0)
{}

void Counting_Player::expose(Card c)
{
	if (int(c.spot)>=8) player_count=player_count-1;
	else if (int(c.spot)<=4) player_count=player_count+1;
	//cout<<player_count<<endl;
}


void Counting_Player::shuffled()
{
	player_count=0;
}

int Counting_Player::bet(unsigned int bankroll, unsigned int minimum)
{
	if (player_count>=2&&(bankroll>=2*minimum))
	{
		return 2*minimum;
	}
	else
	{
		return minimum;
	}
}


static Simple_Player simplayer;
static Counting_Player countplayer;


extern Player *get_Simple()
{
	return &simplayer;
}

extern Player *get_Counting()
{
	return &countplayer;
}

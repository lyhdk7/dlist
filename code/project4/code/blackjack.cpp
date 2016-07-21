#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "player.h"
#include "deck.h"
#include "hand.h"
#include "rand.h"
using namespace std;


int main(int argc, char *argv[])
{
	int num_bandroll;
	int num_hands;

	Player *our_player;
	
	num_bandroll=atoi(argv[1]);
	num_hands=atoi(argv[2]);

	string sim_count;
	sim_count.assign(argv[3]);

	if (sim_count=="simple")
	{
		our_player=get_Simple();
		//cout<<"1";
	}
	else
	{
		our_player=get_Counting();
		//cout<<"2";
	}


	Deck our_deck;

	cout<<"Shuffling the deck\n";

	for (int i=0; i<7; i++)
	{
		int num_cut;
		num_cut=get_cut();
		our_deck.shuffle(num_cut);
		
		cout<<"cut at "<<num_cut<<endl;
		our_player->shuffled();
	}

	int thishand=0;

	Hand hand_player;
	Hand hand_dealer;


	while(num_bandroll>=5&&thishand<num_hands)
	{



		thishand++;
		cout<<"Hand "<<thishand<<" bankroll "<<num_bandroll<<endl;
		if (our_deck.cardsLeft()<20)
		{
			cout<<"Shuffling the deck\n";
			for (int i=0; i<7; i++)
			{
				int num_cut;
				num_cut=get_cut();
				our_deck.shuffle(num_cut);
				
				cout<<"cut at "<<num_cut<<endl;
				our_player->shuffled();
			}

		}

		Card dealer_first_card;

		Card dealer_hole_card;


		int wager=our_player->bet(num_bandroll, 5);
		cout<<"Player bets "<<wager<<endl;

		for (int i=0; i<4; i++)
		{
			if (i==0||i==2)
			{
				Card card_deal;
				card_deal=our_deck.deal();
				hand_player.addCard(card_deal);
				our_player->expose(card_deal);
				cout<<"Player dealt "<<SpotNames[int(card_deal.spot)]<<" of "<<SuitNames[int(card_deal.suit)]<<endl;

			}
			else if (i==1)
			{
				Card card_deal;
				card_deal=our_deck.deal();
				dealer_first_card=card_deal;
				hand_dealer.addCard(card_deal);
				our_player->expose(card_deal);
				cout<<"Dealer dealt "<<SpotNames[int(card_deal.spot)]<<" of "<<SuitNames[int(card_deal.suit)]<<endl;
			}
			else if (i==3)
			{
				Card card_deal;
				card_deal=our_deck.deal();
				dealer_hole_card=card_deal;
				hand_dealer.addCard(card_deal);
				
				//cout<<"Dealer dealt "<<SpotNames[int(card_deal.spot)]<<" of "<<SuitNames[int(card_deal.suit)]<<endl;
			}
		}
		//cout<<hand_player.handValue().count<<endl;

		if (hand_player.handValue().count==21&&hand_player.handValue().soft==1)
		{
			int money_win=3*wager/2;
			cout<<"Player dealt natural 21\n";
			num_bandroll=num_bandroll+money_win;
		}
		else
		{
			while (our_player->draw(dealer_first_card, hand_player))
			{
				Card card_next;
				card_next=our_deck.deal();
				our_player->expose(card_next);
				hand_player.addCard(card_next);
				cout<<"Player dealt "<<SpotNames[int(card_next.spot)]<<" of "<<SuitNames[int(card_next.suit)]<<endl;


			}
			cout<<"Player's total is "<<hand_player.handValue().count<<endl;
			if (hand_player.handValue().count>21)
			{
				cout<<"Player busts\n";
				num_bandroll=num_bandroll-wager;
			}
			else
			{
				our_player->expose(dealer_hole_card);
				cout<<"Dealer's hole card is "<<SpotNames[int(dealer_hole_card.spot)]<<" of "<<SuitNames[int(dealer_hole_card.suit)]<<endl;
				while (hand_dealer.handValue().count<17)
				{
					Card card_dealer_next;
					card_dealer_next=our_deck.deal();
					our_player->expose(card_dealer_next);
					hand_dealer.addCard(card_dealer_next);
					cout<<"Dealer dealt "<<SpotNames[int(card_dealer_next.spot)]<<" of "<<SuitNames[int(card_dealer_next.suit)]<<endl;
				}
				cout<<"Dealer's total is "<<hand_dealer.handValue().count<<endl;
				if (hand_dealer.handValue().count>21)
				{
					cout<<"Dealer busts\n";
					num_bandroll=num_bandroll+wager;
				}
				else
				{
					if (hand_dealer.handValue().count>hand_player.handValue().count)
					{
						cout<<"Dealer wins\n";
						num_bandroll=num_bandroll-wager;
					}
					else if (hand_dealer.handValue().count<hand_player.handValue().count)
					{
						cout<<"Player wins\n";
						num_bandroll=num_bandroll+wager;
					}
					else
					{
						cout<<"Push\n";
						num_bandroll=num_bandroll;
					}
				}
			}



		}

		hand_player.discardAll();
		hand_dealer.discardAll();



		



		//cout<<"Player has "<<num_bandroll<<" after "<<thishand<<" hands\n";

		




	}

	if (num_hands==0)
	{
		cout<<"Player has "<<num_bandroll<<" after "<<num_hands<<" hands\n";
	}
	else
	{
		cout<<"Player has "<<num_bandroll<<" after "<<thishand<<" hands\n";
	}



	return 0;









}
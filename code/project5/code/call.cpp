#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "dlist.h"
#include "dlist.cpp"

using namespace std;


struct passenger
{
	int timestamp;
	string name;
	string status;
	int duration;
};






int main()
{
	int lines;


	
	Dlist<passenger> regular;
	Dlist<passenger> silver;
	Dlist<passenger> gold;
	Dlist<passenger> platinum;

	cin>>lines;

	int left_lines=lines;

	int time_tick=0;

	int busy_agent=0;

	int load_queues=0;

	int event_tick=-1;


	while(left_lines>0||busy_agent!=0||!regular.isEmpty()||!silver.isEmpty()||!gold.isEmpty()||!platinum.isEmpty())
	{
		cout<<"Starting tick #"<<time_tick<<endl;

		
		if (left_lines>0&&event_tick==-1) cin>>event_tick;

		while(event_tick==time_tick)
		{
			string event_name;
			string event_status;
			int event_duration;
			cin>>event_name>>event_status>>event_duration;

			passenger* event_passenger=new passenger;
			event_passenger->timestamp=time_tick;
			event_passenger->name=event_name;
			event_passenger->status=event_status;
			event_passenger->duration=event_duration;

			--left_lines;

			cout<<"Call from "<<event_name<<" a "<<event_status<<" member"<<endl;



			if (event_status=="regular")
			{
				regular.insertFront(event_passenger);
			}
			else if (event_status=="silver")
			{
				silver.insertFront(event_passenger);
			}
			else if (event_status=="gold")
			{
				gold.insertFront(event_passenger);
			}
			else
			{
				platinum.insertFront(event_passenger);
			}

			



			if (left_lines>0) cin>>event_tick;
			else event_tick=-1;
		}

		//cout<<"success"<<busy_agent<<endl;

		if (busy_agent==0)
		{

			if (!platinum.isEmpty())
			{
				passenger* answer_event=platinum.removeBack();
				busy_agent=answer_event->duration;
				cout<<"Answering call from "<<answer_event->name<<endl;
				delete answer_event;
			}
			else if (!gold.isEmpty())
			{
				
				passenger* answer_event=gold.removeBack();	
				busy_agent=answer_event->duration;
				cout<<"Answering call from "<<answer_event->name<<endl;
				delete answer_event;

			}
			else if (!silver.isEmpty())
			{
				passenger* answer_event=silver.removeBack();
				busy_agent=answer_event->duration;
				cout<<"Answering call from "<<answer_event->name<<endl;
				delete answer_event;
			}
			else if (!regular.isEmpty())
			{
				passenger* answer_event=regular.removeBack();
				busy_agent=answer_event->duration;
				cout<<"Answering call from "<<answer_event->name<<endl;
				delete answer_event;
			}
		}



		

		if (busy_agent!=0) --busy_agent;
		++time_tick;

		


	}

	cout<<"Starting tick #"<<time_tick<<endl;


	




	return 0;
}


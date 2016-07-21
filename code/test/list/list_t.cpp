#include <iostream>
#include "list_t.h"

using namespace std;

int list_t::getSize()
{
	node *current=header;
	int num=0;
	while(current)
	{
		num++;
		current=current->next;
	}
	return num;

}

bool list_t::isEmpty()
{
	return !header;
}

void list_t::insert(int v)
{
	node *np=new node;
	np->value=v;
	np->next=header;
	header=np;
}

int list_t::remove()
{
	if (isEmpty())
	{
		listIsEmpty e;
		throw e;
	}
	node *np=header;
	int val=header->value;
	header=header->next;
	delete np;

	return val;
}


void list_t::copyList(node *p)
{
	if (p==NULL) return;
	else
	{
		copyList(p->next);
		insert(p->value);
	}
}


list_t::list_t()
{
	header=NULL;
}

list_t::list_t(const list_t& l)
{
	header=NULL;
	copyList(l.header);

}

void list_t::removeAll()
{
	while(!isEmpty())
	{
		remove();
	}
}

list_t::~list_t()
{
	removeAll();
}


list_t& list_t::operator=(const list_t& l)
{
	removeAll();
	copyList(l.header);
	return *this;
}

void list_t::printp(node* p)
{
	if (p!=NULL) 
		{
	//else return;
	cout<<p->value<<endl;
	printp(p->next);
}
}

void list_t::print()
{
	printp(header);
}
#ifndef DLIST_CPP
#define DLIST_CPP
#include <iostream>


using namespace std;


template <class T>
bool Dlist<T>::isEmpty()
{
	return first==NULL;
}

template <class T>
void Dlist<T>::insertFront(T *op)
{

	if (isEmpty())
	{

		node *help=new node;
		help->op=op;
		help->next=NULL;
		help->prev=NULL;
		first=help;
		last=help;

		
	}
	else
	{
		node *help=new node;
		help->op=op;
		help->next=first;
		help->prev=NULL;
		first->prev=help;
		first=help;
		
	}
}

template <class T>
void Dlist<T>::insertBack(T *op)
{
	if (isEmpty())
	{
		node *help=new node;
		help->op=op;
		help->next=NULL;
		help->prev=NULL;
		first=help;
		last=help;
	}
	else
	{
		node *help=new node;
		help->op=op;
		help->next=NULL;
		help->prev=last;
		last->next=help;
		last=help;
	}
}

template <class T>
T* Dlist<T>::removeFront()
{

	if (isEmpty())
	{
		emptyList e;
		throw e;
	}
	else
	{


		node *victim=first;

		T *result=victim->op;

		first=victim->next;

		if (first!=NULL) first->prev=NULL;
		else 
		{
			last=NULL;
			first=NULL;
		}

		
		delete victim;
		return result;
	}
}

template <class T>
T* Dlist<T>::removeBack()
{
	if (isEmpty())
	{
		emptyList e;
		throw e;
	}
	else
	{
		node *victim=last;
		T *result=victim->op;
		last=victim->prev;


		if (last!=NULL) last->next=NULL;
		else 
		{
			last=NULL;
			first=NULL;
		}

		
		delete victim;
		return result;
	}
}


template <class T>
void Dlist<T>::removeAll()
{
	while(!isEmpty())
	{
		T *receive;
		receive=removeFront();
		delete receive;
	}
}


template <class T>
void Dlist<T>::copyAll(const Dlist &l)
{
	node *help=l.last;
	while (help!=NULL)
	{
		T *inserthelp=new T(*(help->op));
		insertFront(inserthelp);
		help=help->prev;
	}
}


template <class T>
Dlist<T>::Dlist()
{
	first=NULL;
	last=NULL;
}

template <class T>
Dlist<T>::Dlist(const Dlist &l)
{
	first=NULL;
	last=NULL;
	copyAll(l);
}

template <class T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l)
{
	if (this!=&l)
	{
		removeAll();
		copyAll(l);
	}
	return *this;
}

template <class T>
Dlist<T>::~Dlist()
{
	removeAll();
}


/*

template <class T>
void Dlist<T>::print()
{
	while (!isEmpty())
	{
		T* help=removeFront();
		cout<<*help<<" ";
	}
}
*/








#endif
#ifndef TEMPLATE_CPP
#define TEMPLATE_CPP



#include <iostream>
#include "template.h"

using namespace std;


template <class T>
bool list_t<T>::isEmpty()
{
	return header==NULL;
}


template <class T>
void list_t<T>::insert(T v)
{
	node *np=new node;
	np->val=v;
	np->next=header;
	header=np;
}

template <class T>
T list_t<T>::remove()
{
	
	node *np=header;
	T val=header->val;
	header=header->next;
	delete np;

	return val;
}

template <class T>
void list_t<T>::removeAll()
{
	while (!isEmpty())
	{
		remove();
	}
}

template <class T>
void list_t<T>::copyList(node* p)
{
	if (p==NULL) return;
	else
	{
		copyList(p->next);
		insert(p->val);
	}
}





template <class T>
list_t<T>::list_t()
{
	header=NULL;
}

template <class T>
list_t<T>::list_t(const list_t& l)
{
	header=NULL;
	copyList(l.header);
}

template <class T>
list_t<T>& list_t<T>::operator=(const list_t& l)
{
	removeAll();
	copyList(l.header);
}

template <class T>
list_t<T>::~list_t()
{
	removeAll();
}

template <class T>
void list_t<T>::print()
{
	node* help=header;
	while(help!=NULL)
	{
		node* p=help->next;
		cout<<help->val<<" ";
		help=p;
	}
}






#endif
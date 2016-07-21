#ifndef TEMPTR_CPP
#define TEMPTR_CPP

#include <iostream>
#include "temptr.h"

using namespace std;

template <class T>
bool list_t<T>::isEmpty()
{
	return header==NULL;
}

template <class T>
void list_t<T>::insert(T* v)
{
	node *np=new node;
	np->val=v;
	np->next=header;
	header=np;
}

template <class T>
T* list_t<T>::remove()
{
	
	node *np=header;
	T* val=header->val;
	header=header->next;
	delete np;
	//delete val;
	return val;
}

template <class T>
void list_t<T>::removeAll()
{
	while (!isEmpty())
	{
		T* op;
		op=remove();
		delete op;
	}
}

template <class T>
void list_t<T>::copyList(node* p)
{
	if (p==NULL) return;
	else
	{
		copyList(p->next);
		T* op=new T(*(p->val));
		insert(op);
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
	return *this;
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
		cout<<*help->val<<" ";
		help=p;
	}
}




#endif
#ifndef TEMPLATE_H
#define TEMPLATE_H

template <class T>
class list_t{
	struct node
	{
		node *next;
		T val;
	};

	node* header;
	void removeAll();
	void copyList(node* p);

public:
	bool isEmpty();
	void insert(T v);
	void print();
	T remove();
	list_t();
	list_t(const list_t& l);
	list_t& operator=(const list_t& l);
	~list_t();


};





#endif
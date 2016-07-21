#ifndef LIST_T_H
#define LIST_T_H



struct node{
	node *next;
	int value;
};

class listIsEmpty{};



class list_t{
	node *header;
	void removeAll();
	void copyList(node *p);
	void printp(node* p);
	
public:
	int getSize();
	bool isEmpty();
	void insert(int v);
	int remove();

	void print();
	list_t();
	list_t(const list_t& l);
	~list_t();
	list_t &operator=(const list_t &l);
	


};




#endif
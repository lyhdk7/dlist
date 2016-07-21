#ifndef INTSETBASE_H
#define INTSETBASE_H




class intsetbaseFull{};

class intsetbase{


public:
 
	
	virtual int indexOf(int v) const =0;
	virtual void insert(int v)=0;
	virtual void remove(int v)=0;
	virtual bool query(int v) const=0;
	virtual int size() const=0;
};




#endif
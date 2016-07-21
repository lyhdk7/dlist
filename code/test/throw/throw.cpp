#include<iostream>

using namespace std;


int test(int x){
	if (x<0) throw 1;
	if (x==0) throw 2.2;
	if (x>0) throw 'c';
	cout<<"success"<<endl;
	return 0;
	
}

int main(){
	int x;
	cin>>x;
	try{
		test(x);	
	}
	catch (int v){
		cout << "int"<<endl;
		throw 1;		// the program will jump out of main() and look for catch block in the caller of main()!!
	}
	catch (double v){
		cout <<"double"<<endl;
	}
	catch (char v){
		cout <<"char"<<endl;	
	}
	catch (int v){
		cout <<"int 2"<<endl;
	}
	catch (...){
		cout<<"hahahahha"<<endl;	
	}
}

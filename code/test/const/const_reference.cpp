#include<iostream>
using namespace std;

int main()
{
  int val=10;
  const int &constval=val;
  constval++;
  cout<<constval<<endl;
  return 0;
}

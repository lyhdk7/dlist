#include<iostream>
using namespace std;
void Permutation(char* pStr, char* pBegin);   

void permutation(char* pStr)  
{  
      Permutation(pStr, pStr);  
}  
  
void Permutation(char* pStr, char* pBegin)  
{  
    if(!pStr || !pBegin)  
        return;  
      
    if(*pBegin == '\0')  
    {  
        cout<<pStr<<endl;  
    }  
    else  
    {  
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)  
        {  
            // swap pCh and pBegin  
            char temp = *pCh;  
            *pCh = *pBegin;  
            *pBegin = temp;  
              
            Permutation(pStr, pBegin + 1);    
            // restore pCh and pBegin  
            temp = *pCh;  
            *pCh = *pBegin;  
            *pBegin = temp;  
        }  
    }  
} 

int main()
{ 
    char str[] ={'a','b','c','d','\0'};
    permutation(str);
    
    return 0;
}
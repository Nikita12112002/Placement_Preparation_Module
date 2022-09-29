#include <iostream>

using namespace std;

int func(string s , int i,int n)
{
    i++;
    while(i<n)
    {
        char curr=s[i];
        char prev=s[i-1];
        
        if((curr-prev==1) || (curr=='a'&&prev=='z'))
        {
            i++;
        }
        else
         break;
    }
    
    return i-1;
}
int longestsubstring(string s)
{
    int n= s.length();
    int i=0,len=0;
    
    while(i<n)
    {
        int end= func(s,i,n);
        len=max(len,end-i+1);
        i=end+1;
    }
    return len;
}
int main()
{
   string s="zabcd";
    cout<< longestsubstring(s)<<endl;

    return 0;
}

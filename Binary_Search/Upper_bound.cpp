#include <iostream>

using namespace std;

int main()
{
    int a[10]={1,2,3,4,6,7,9,10};
    int ele=9;
    int mid;
    int low=0,high=9,flag=0;
    
    while(low<high)
    {
         mid= (low+high)/2;
        
     
        
         if(a[mid]<=ele)
        low=mid+1;
        
        else
         high=mid;
    }
    
    cout<<a[low]<<endl;
    return 0;
}

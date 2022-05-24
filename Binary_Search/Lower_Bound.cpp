#include <iostream>

using namespace std;

int main()
{
    int a[10]={1,2,3,4,6,7,9,10};
    int ele=8;
    int mid;
    int low=0,high=9,flag=0;
    
    while(high-low>1)
    {
         mid= (low+high)/2;
        
     
        
         if(a[mid]<ele)
        low=mid+1;
        
        else
         high=mid;
    }
    
    if(a[low]>=ele)
    {
        cout<<a[low];
    }
    
    else if(a[high]>=ele)
    {
        cout<<a[high];
    }
    return 0;
}

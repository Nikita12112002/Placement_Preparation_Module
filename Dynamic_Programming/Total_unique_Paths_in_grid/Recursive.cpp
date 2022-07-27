#include <bits/stdc++.h>
int f(int i ,int j)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0 ;
   int up= f(i-1,j);
   int left= f(i,j-1);
    return up+left;
}
int uniquePaths(int m, int n) {
	// Write your code here.
     if(n==0 && m==0)
         return 0;
     
      return f(m-1,n-1);
       
    
}
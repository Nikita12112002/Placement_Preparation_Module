class Solution {
public:
    
    bool check(string a , string b)
    {
        int i,j;
        int n=a.size();
        int m=b.size();
        for(i=0 ; i<=n-m ;i++)
        {
            for(j=0 ;j<m;j++)
            {
                if(a[i+j]!=b[j])
                    break;
            }
            
            if(j==m)
                return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) 
    {
        int n=a.size();
        int m=b.size();
        int ans=1;
        string temp=a;
        while(a.size()<b.size()) //remember not to use n and m as size because size of a is continuosly changing in this                                   while loop
        {
            a=a+temp;
            ans++;
        }
        
        if(check(a,b)==true)  // if modified a has b as substring.
            return ans;
        else if(check(a+temp,b)==true)  // if modified a has already some part of b ;refer to ex-1
          return ans+1;
       
        return -1;
    }
};
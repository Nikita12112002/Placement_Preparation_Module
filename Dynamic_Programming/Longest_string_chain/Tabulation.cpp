class Solution {
public:
    bool compare_strings(string& a , string& b)
    {
        if(a.size()-b.size()!=1) 
            return false;
        
        int i=0 , j=0;
        while(i<a.size()) // we know a is larger 
        {
            if( j< b.size() && a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        
        if( j==b.size())
            return true;
        return false;
    }
    
    bool static comp(string &a , string &b)
    {
        return a.size()<b.size();
    }
    


    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>dp(n,1);
        
        for(int i=0 ; i<n ;i++)
        {
            for(int prev=0 ; prev<i ;prev++)
            {
                if(compare_strings(words[i],words[prev]) && 1+dp[prev]>dp[i])
                {
                    dp[i]= 1+dp[prev];
                }
            }
        }
        
        int  ans=-1;
        for(int i=0 ;i<n ;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                
            }
        }
        
        return ans;
    }
};
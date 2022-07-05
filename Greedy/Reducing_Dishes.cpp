class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
       
        sort(s.begin(),s.end());
        
        int n =s.size(),sum=0,i;
        
        for(i=n-1 ;i>=0 ;i--)
        {
            sum = sum+s[i];
            
            if(sum<0)
                break;
        }
        
        int j=i++;
        int time=0 , ans=0;
        
        for(int j=i ;j<n ;j++)
        {
            time++;
            ans=ans+(time*s[j]);
        }
        return ans;
    }
};
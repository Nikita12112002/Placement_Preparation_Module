class Solution {
public:
    int largestInteger(int num) {
       
        string s=to_string(num);
        
        priority_queue<int>p;
        priority_queue<int>q;
        
        for(int i=0 ;i<s.size() ;i++)
        {
            if((s[i]-'0')%2==0)
                p.push(s[i]-'0');
            
            else
                q.push(s[i]-'0');
        }
        
        int ans=0;
        
       for(int i=0 ; i<s.size() ;i++)
       {
           ans=ans*10;
           
           if((s[i]-'0')%2==0)
           {
               ans=ans+p.top();
               p.pop();
           }
           else
           {   ans=ans+q.top();
              q.pop();
           }
       }
        
        return ans;
    }
};
// TC: O(n) SC:O(n)
int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>m;
        int j=0 , length=0 ,maxi=0;
        
        for(int i=0 ;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end() && j<=m[s[i]])
                j=m[s[i]]+1; // update the starting index of new window
            
            m[s[i]]=i; // push the element if it is not present in map or even if present update its current index.
            
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
class Solution {
public:
    //TC:O(size Of first_string * no of strings)
    string longestCommonPrefix(vector<string>& s) {
        
       string ans="";
        for(int i=0 ;i<s[0].size();i++)
        {
            for(int j=1 ;j<s.size();j++)
            {
                if(s[0][i]!=s[j][i])
                   return ans;
            }
          ans=ans+s[0][i];
        }
        return ans;           
                   
    }
};

// can also be solve using trie data structures.
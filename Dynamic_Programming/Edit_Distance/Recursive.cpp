class Solution {
public:
    int dfs(string &word1 , string &word2 , int i , int j)
    {
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(word1[i]==word2[j])
            return dfs(word1 , word2 , i-1 , j-1);
        
        return 1+min(dfs(word1,word2,i,j-1),min(dfs(word1,word2,i-1,j) ,dfs(word1,word2,i-1,j-1)));
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        return dfs(word1,word2,n-1,m-1);
        
    }
};
class Solution {
public:
    
    int dfs(int i , int j ,vector<vector<int>>& image , int color , int val)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size())
            return 0;
        if(image[i][j]!=val)
            return 0;
        if(image[i][j]==color)
            return 1;
        image[i][j]=color;
        if(dfs(i-1,j,image,color,val));
        if(dfs(i+1,j,image,color,val));
        if(dfs(i,j-1,image,color,val));
        if(dfs(i,j+1,image,color,val));
        return 1;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};
class Solution {
public:
    
    bool isValid(int row , int col , int c , vector<vector<char>>&board)
    {
        int i ,j;
        
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]==c)
                return false;
        }
        
        for(int j=0 ;j<board[0].size();j++)
        {
            if(board[row][j]==c)
                return false;
        }
        
        int p=(row/3)*3;
        int q=(col/3)*3;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0 ;j<3 ;j++)
            {
                if(board[p+i][q+j]==c)
                    return false;
            }
        }
       return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        for(int i=0 ; i<board.size() ;i++)
        {
            for(int j=0 ; j<board[0].size() ;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int c='1' ; c<='9' ; c++)
                    {
                        if(isValid(i,j,c,board)==true)
                        {
                            board[i][j]=c;
                            
                             if(solve(board)==true)
                                return true;
                            else
                            {     
                              board[i][j]='.';
                            }
                        }
                            
                    }
                    
                    return false; // if none of the value can fit ,return false
            // when false is returned then backtrack step will execute and then try for other possible values of c 
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};
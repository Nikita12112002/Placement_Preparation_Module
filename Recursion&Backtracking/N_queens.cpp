class Solution {
public:
    
    void solve(int col , vector<string>&board , vector<vector<string>>&ans , int n)
    {
        if(col==n)// it means all the queens are placed successfully so we can add that vector into ans;
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0 ; i<n ;i++)
        {
            if(isSafe(i,col,board,n)==true) // if that position is safe to place a queen
            {
                board[i][col]='Q';          // then place the queen
                solve(col+1,board,ans,n); // it means Q has been placed in first col and now check for second col
                board[i][col]='.' ;// backtracking step
            }
        }
    }
    
    bool isSafe(int row , int col , vector<string>board , int n)
    {
        int i,j;
        // going left
        
       for(i=col ; i>=0 ;i--)
       {
           if(board[row][i]=='Q')  // means there is already a queue at the left side so we can not place Q
           
               return false;   
       }
        
       // check for up diagonal towards left side
        
        for(i=row ,j=col ; i>=0 &&j>=0 ; i-- ,j--)
        {
            if(board[i][j]=='Q')
                return false;
 
        }
        
        // down diagonal towards left
        
        for(i=row ,j=col ; i<n&&j>=0 ; i++,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        
        return true; // means posiiton is safe and we can place the queue
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n);
        
        for(int i=0 ;i<n;i++)
        {
            board[i]=s;
        }
        
        solve(0,board,ans,n);
        return ans;
    }
};
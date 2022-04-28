bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low=0,high=m*n-1;
        
        while(low<=high)
        {
           int mid=(low+high)/2;
            
            int r = matrix[mid/m][mid%m]; 
            
            //mid is a imaginery index so to compute a real row and col we have to divide it by col
            
            
            if(r==target)
                return true;
            
            else if(r<target)
            {
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return false;
    }
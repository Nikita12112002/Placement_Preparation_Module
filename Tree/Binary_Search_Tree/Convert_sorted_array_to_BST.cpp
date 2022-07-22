class Solution {
public:
    
    TreeNode* dfs(vector<int>&nums , int left , int right)
    {
        if(left>right)
            return NULL;
        
        int mid = left+(right-left)/2;
        TreeNode* node= new TreeNode(nums[mid]);
        node->left=dfs(nums,left,mid-1);
        node->right=dfs(nums,mid+1,right);
        
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0)
            return NULL;
       return dfs(nums,0,nums.size()-1);
        
    }
};
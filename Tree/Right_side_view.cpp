class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>res;
        rightView(root,0,res);
        return res;
        
    }
    
    void rightView(TreeNode* root , int level , vector<int>&res)
    {
        if(root==NULL)
            return;
        
        if(res.size()==level)
            res.push_back(root->val);
        
        rightView(root->right , level+1 , res);
        rightView(root->left , level+1 , res);
         
        return;
        
    }
};
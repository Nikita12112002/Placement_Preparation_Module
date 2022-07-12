class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return Validate(root, LONG_MIN, LONG_MAX );
        
    }
    
    bool Validate(TreeNode* root ,long long min , long long max)
    {
        if(root==NULL)
            return true;
        
        if(root->val>=max || root->val<=min)
            return false;
        
     return  Validate(root->left , min , root->val) && Validate(root->right , root->val , max);
        
    }
};
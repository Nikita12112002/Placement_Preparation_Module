class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        return symm(root->left,root->right);
        
    }
    
    bool symm(TreeNode* left , TreeNode* right)
    {
        if(left==NULL || right==NULL)
            return left==right;
        
        if(left->val != right->val)
            return false;
        
       return symm(left->left,right->right) && symm(left->right , right->left);
        
    }
};
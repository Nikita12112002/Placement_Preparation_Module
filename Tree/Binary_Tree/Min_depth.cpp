class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int left = minDepth(root->right);
        int right = minDepth(root->left);
        
        if(left==0 || right==0) // this is to handle skewed tree. check sample ex -2
        {
            return 1+max(left,right);
        }
        return 1+min(left,right);
        
    }
};
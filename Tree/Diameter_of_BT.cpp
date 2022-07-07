class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
       int maxi=0;
    
       dia(root,maxi);
        
        return maxi;
        
        
    }
    
    int dia(TreeNode* root , int &maxi)
    {
         if(root==NULL)
            return 0;
        
        int left = dia(root->left , maxi);
        int right = dia(root->right , maxi);
        
         maxi = max(maxi,left+right);
        
        return 1+max(left,right);
    }
    
    
};
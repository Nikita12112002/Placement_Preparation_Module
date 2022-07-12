class Solution {
public:
    
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL)
            return root->right;
        
        if(root->right==NULL)
            return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* rightMostChildOfLeft = findRightMost(root->left);
        
        rightMostChildOfLeft->right = rightChild;
        
        return root->left;

    }
    
    TreeNode* findRightMost(TreeNode* root)
    {
        while(root->right)
        {
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val==key)
            return helper(root);
        
        TreeNode* dummy=root;
        
        while(root!=NULL)
        {
            if(root->val>key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left=helper(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else
            {
                if(root->right && root->right->val==key)
                {
                    root->right=helper(root->right);
                    break;
                }
                else
                    root=root->right;
            }

        }
        return dummy;
    }
};
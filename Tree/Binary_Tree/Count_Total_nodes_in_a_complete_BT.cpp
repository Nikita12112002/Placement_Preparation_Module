class Solution {
public:
    long long findLeftHeight(TreeNode* node)
    {
        long long l=0;
        while(node)
        {
            l++;
            node=node->left;
        }
        return l;
    }
    
     long long findRightHeight(TreeNode* node)
    {
        long long r=0;
        while(node)
        {
            r++;
            node=node->right;
        }
        return r;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        long lh = findLeftHeight(root);
        long rh = findRightHeight(root);
        
        if(lh==rh)
            return (1<<lh)-1;  // 2 power lh -1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
        
    }
};
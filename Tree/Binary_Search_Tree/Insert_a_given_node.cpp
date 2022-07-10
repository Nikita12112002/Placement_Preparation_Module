// Recursive

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL)
          return new  TreeNode(val);
        if(val<root->val)
            root->left= insertIntoBST(root->left,val);
        else
           root->right= insertIntoBST(root->right,val);
        
        return root;
    }
};

// iterative

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* node = root;
        while(node)
        {
            if(val>=node->val)
            {
                if(node->right==NULL)
                {
                  node->right=new TreeNode(val);
                    break;
                }
                else
                    node=node->right;
                    
            }
            else
            {
                if(node->left==NULL)
                {
                   node->left = new TreeNode(val);
                    break;
                }
                else
                    node=node->left;
            }
            
        }
        return root;
    }
};
// Recursive-

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>in;
        inorder(root,in);
        return in;
        
    }
    
    void inorder(TreeNode* root ,vector<int>&in)
    {
        if(root==NULL)
            return;
        
        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right ,in);
        
        
    }
};

// iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>in;
       
        stack<TreeNode*>st;
        
        
        while(true)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            
            else
            {
                if(st.empty()==true)
                    break;
                
                root =st.top();
                st.pop();
                
                in.push_back(root->val);
                root=root->right;
            }
        }
        return in;
        
    }
};
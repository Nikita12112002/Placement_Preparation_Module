// Recursive

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
       vector<int>v;
        pre(root,v);
        return v;
        
        
    }
    
    void pre(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v);
        
    }
};

// iterative-

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>pre;
        stack<TreeNode*>st;
        st.push(root);
        
        if(root==NULL)
            return pre;
        
        while(!st.empty())
        {
           auto  node = st.top();
            st.pop();
            
            pre.push_back(node->val);  
            
            if(node->right!=NULL)
                st.push(node->right);
            
            if(node->left!=NULL)
                st.push(node->left);
                
              
        }
        
        return pre;
        
    }
};
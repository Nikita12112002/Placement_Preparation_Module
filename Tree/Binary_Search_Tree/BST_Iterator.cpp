class BSTIterator {
public:
    
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        
        pushAll(root);
        
    }
    
    void pushAll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
    int next() {
        
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        
        return !st.empty();
        
    }
};

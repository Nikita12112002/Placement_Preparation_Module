// Recursive

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
         
        post(root,ans);
        return ans;
    }
    void post(TreeNode* root , vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        post(root->left,ans);
        
        post(root->right,ans);
        ans.push_back(root->val);
    }
};

// iterative

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>post;
        
        if(root==NULL)
            return post;
        
        stack<TreeNode*>st1 ,st2;
        
        st1.push(root);
        
        while(!st1.empty())
        {
            auto node = st1.top();
            st1.pop();
            st2.push(node);
            
            if(node->left!=NULL)
                st1.push(node->left);
            if(node->right!=NULL)
                st1.push(node->right);
            
        
        }
        
        while(!st2.empty())
        {
            post.push_back(st2.top()->val);
            st2.pop();
        }
        
        return post;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        TreeNode* temp;
        vector<vector<int>>v;
       
        q.push(root);
        
        if(root==NULL)
            return v;
        
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int>ans;
            
            for(int i=0 ;i<n;i++)
            {
             temp = q.front();
                q.pop();
                
                ans.push_back(temp->val);
            
           if(temp->left!=NULL)
           q.push(temp->left);
                
                if(temp->right!=NULL)
            q.push(temp->right);
           
            }
           v.push_back(ans);
        }
        return v;
    }
};
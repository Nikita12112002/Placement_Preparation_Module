class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode* ,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>m;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x= p.second.first;
            int y = p.second.second;
            
            m[x][y].insert(node->val);
            
            if(node->left)
                q.push({node->left , {x-1 , y+1}});
            
            if(node->right)
                q.push({node->right ,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        
        for(auto p:m)
        {
            vector<int>col;
            for(auto it:p.second)
            {
              col.insert(col.end(),it.second.begin(),it.second.end());
            }
          ans.push_back(col);
        }
        return ans;
    }
};
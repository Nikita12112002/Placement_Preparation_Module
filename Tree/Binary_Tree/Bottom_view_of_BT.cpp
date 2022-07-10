class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>ans;
         map<int,int>m;
        if(root==NULL)
        return ans;
        queue<pair<Node* ,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            auto node = it.first;
            int vertical = it.second;
            
            m[vertical]=node->data;
            
            if(node->left)
            q.push({node->left,vertical-1});
            
            if(node->right)
            q.push({node->right,vertical+1});
        }
        
        for(auto it : m)
        ans.push_back(it.second);
        
        return  ans;
        
    }
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int>ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            auto node= it.first;
            int vertical = it.second;
            
            if(m.find(vertical)==m.end())
             m[vertical]=node->data;
             
             if(node->left)
             q.push({node->left,vertical-1});
             
             if(node->right)
             q.push({node->right , vertical+1});
        }
        
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

};

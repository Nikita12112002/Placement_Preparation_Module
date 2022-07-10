class Solution {
public:
    void markParent(TreeNode* root, TreeNode* target , int k , unordered_map<TreeNode*,TreeNode*>&par)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                par[node->left]=node;
            }
            
            if(node->right)
            {
                q.push(node->right);
                par[node->right]=node;
            }
            
        }
            
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>par;
        
        markParent(root,target,k,par);
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        
        int dis=0;
        
        while(!q.empty())
        {
            int size = q.size();
            
           
            if(dis==k)
            {
                break;
            }
            
            dis++;
            
        for(int i=0 ;i<size ;i++)
        {  
            auto node = q.front();
            q.pop();
            
            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left]=true;
            }
            
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right]=true;
            }
            
            while(par[node] && !visited[par[node]])
            {
                q.push(par[node]);
                visited[par[node]]=true;
            }

        }
    } 
        
        vector<int>ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
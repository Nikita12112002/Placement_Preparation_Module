class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans=0 , first ,last;
        
        while(!q.empty())
        {
            long long sz = q.size();
            long long mini = q.front().second;
            
            for(int i=0 ; i<sz ;i++)
            {
                long long index = q.front().second-mini;
                auto cur=q.front().first;
                q.pop();
                
                if(i==0)
                   first=index;
                
                if(i==sz-1)
                    last=index;
                
                if(cur->left)
                    q.push({cur->left,index*2+1});
                
                if(cur->right)
                    q.push({cur->right,index*2+2});
            }
            
            ans = max(ans,last-first+1);
            
        }
       return ans;  
    }
};
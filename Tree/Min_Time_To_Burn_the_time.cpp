class Solution {
  public:
  
  Node* markParents(Node* root , int start , unordered_map<Node*,Node*>&par)
  {
      queue<Node*>q;
      q.push(root);
      Node* res;
      
      while(!q.empty())
      {
          
          auto node = q.front();
          q.pop();
          
          if(node->data==start)
            res=node;
            
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
     return res; 
  }
    int minTime(Node* root, int start) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>par;
      Node*target = markParents(root,start,par);
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(target);
        visited[target]=true;
        int time=0;
        
        while(!q.empty())
        {
            
            int size=q.size();
            int flag=0;
            
            for(int i=0 ;i<size ;i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    flag=1;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                
                if(node->right && !visited[node->right])
                {
                    flag=1;
                    q.push(node->right);
                    visited[node->right]=true;
                }
                
                if(par[node] && !visited[par[node]])
                {
                    flag=1;
                    q.push(par[node]);
                    visited[par[node]]=true;
                }
                
            }
            
            if(flag==1)
            time++;
            
        }
        return time;
    }
};
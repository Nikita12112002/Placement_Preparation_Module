/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

bool leaf(Node* root)
{
    return ! root->left && !root->right;
}

  void addrightBoundary(Node* root , vector<int>&res)
  {
      vector<int>temp;
      
       Node* cur=root->right;
       
       while(cur)
       {
           if(!leaf(cur))
            temp.push_back(cur->data);
            
            if(cur->right)
            cur=cur->right;
            
            else
            cur=cur->left;
            
       }
       
       for(int i=temp.size()-1 ;i>=0 ;i--)
       res.push_back(temp[i]);
  }
   
   void addLeaves(Node* root , vector<int>&res)
   {
       if(leaf(root))
       {
           res.push_back(root->data);
           return;
       }
       
       if(root->left)
         addLeaves(root->left , res);
        
       if(root->right)
         addLeaves(root->right , res);
   }
 
   void addleftBoundary(Node* root , vector<int>&res)
   {
       Node * cur= root->left;
       
        while(cur)
       {
           if(!leaf(cur))
            res.push_back(cur->data);
            
            if(cur->left)
            cur=cur->left;
            
            else
            cur=cur->right;
       }
   }
   
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int>res;
        
        if(root==NULL)
         return res;
         
         if(!leaf(root))
           res.push_back(root->data);
           
         addleftBoundary(root,res);
         addLeaves(root,res);
         addrightBoundary(root,res);
         
         return res;
         
    }
};




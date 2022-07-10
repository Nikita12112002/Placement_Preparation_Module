void lf(Node* root , int level , vector<int>&res)
{
    if(root==NULL)
    return ;
    
    if(res.size()==level)
    res.push_back(root->data);
    
    lf(root->left,level+1,res);
    lf(root->right , level+1 , res);
    return;
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   lf(root , 0 , res);
   return res;
   
}
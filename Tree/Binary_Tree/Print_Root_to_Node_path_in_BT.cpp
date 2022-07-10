bool path(TreeNode* root , int B , vector<int>&res)
{
    if(root==NULL)
     return false;
    
    res.push_back(root->val);
    
    if(root->val==B)
     return true;
     
    if(path(root->left , B , res) || path(root->right , B , res))
    return true;
    
    res.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int>res;
    if(A==NULL)
    return res;
    path(A,B,res);
    return res;
}

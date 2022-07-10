int floorInBST(TreeNode<int> * node, int x)
{
    // Write your code here.
        int floor=-1;
    if(node==NULL)
        return 0;
  while(node)
  {
    if(x==node->val)
        return x;
    
    else if(x>node->val)
    {
        floor=node->val;
         node = node->right;
    }  
    
    else
    {
        
        node=node->left;
    }
    
}
    return floor;
}
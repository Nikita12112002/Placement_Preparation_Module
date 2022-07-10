class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* node = root;
        
        if(root==NULL)
        return NULL;
        
        Node* succ=NULL;
        
        while(node)
        {
            if(x->data>=node->data)
            {
                node=node->right;
            }
            else
            {
                succ=node;
               node= node->left;
            }
        }
        
        return succ;
    }
};

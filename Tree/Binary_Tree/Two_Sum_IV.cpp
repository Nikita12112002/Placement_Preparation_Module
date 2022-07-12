class BSTIterator
{
    
    stack<TreeNode*>st;
    bool reverse=true;
  public:  
    BSTIterator(TreeNode* root , bool isReverse)
    {
        reverse=isReverse;
        pushALL(root);
    }
    
    void pushALL(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse==true)
               root=root->right;
            else
                root=root->left;
        }
    }
    
    bool hasnext()
    {
        return !st.empty();
    }
    
    int next()
    {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse)
            pushALL(temp->right);
        else
            pushALL(temp->left);
       return temp->val;
    }
    
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        
        if(root==NULL)
            return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if(i+j==k)
                return true;
            if(i+j<k)
               i= l.next();
            else
               j= r.next();
        }
        return false;
    }
};
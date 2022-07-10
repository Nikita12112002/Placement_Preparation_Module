class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
             vector<int>inorder;
        TreeNode* curr = root;
        
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            
            else
            {
                TreeNode* prev = curr->left;
                
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;
                
                if(prev->right==NULL)  // making thread
                {
                  prev->right=curr;    // thread is made by connecting rightmost node to the curr root node
                    curr=curr->left;
                }
                
                else  // destroying threads
                {
                    prev->right=NULL ; //destroyed;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
        
        
    }
};
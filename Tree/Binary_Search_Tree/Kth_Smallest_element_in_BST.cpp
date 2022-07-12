//can be solves using three ways --
//1- recursive-> TC:O(n) , SC:O(n)
//2- Iterative - TC:O(n) , SC:O(n)
//3- Morris Traversal : O(n) , SC:O(1);

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int count=0 , ans=0;
        
        if(root==NULL)
            return 0;
        
        TreeNode* cur=root;
        
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                count++;
        
            if(count==k)
                ans=cur->val;
            cur=cur->right;
            }
            
            else
            {
                TreeNode*prev = cur->left;
                
                while(prev->right!=NULL && prev->right!=cur)
                    prev=prev->right;
                
                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                
                else
                {
                    prev->right=NULL;
                    count++;
                    
                    if(count==k)
                        ans=cur->val;
                    
                    cur=cur->right;
                }
            }
        }
        
       return ans; 
    }
};
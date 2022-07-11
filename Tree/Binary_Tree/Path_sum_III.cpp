// Brute force - O(n2)

class Solution
{
public:
    long long count = 0;
    int pathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return 0;

        AllPath(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }

    void AllPath(TreeNode *root, long long sum)
    {
        if (root == NULL)
            return;

        if (sum - root->val == 0)
            count++;

        AllPath(root->left, sum - root->val);
        AllPath(root->right, sum - root->val);
    }
};

//iterative

class Solution {
public:
 
    //optimal O(n)..
    unordered_map<int,int>m;
    long long count=0;
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return 0;
        
        path(root , targetSum,0);
        
        return count;
        
    }
    
    void path(TreeNode* root ,long long target , long long sum)
    {
        if(root==NULL)
            return;
        
         sum = sum+root->val;
        
        if(sum==target)
            count++;
        
        if(m.find(sum-target)!=m.end())
            count = count + m[sum-target];
        
        m[sum]++;
        
        path(root->left , target , sum);
        path(root->right , target , sum);
        
        m[sum]--;
    }
    
        
};
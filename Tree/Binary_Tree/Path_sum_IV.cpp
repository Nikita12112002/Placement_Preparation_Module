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
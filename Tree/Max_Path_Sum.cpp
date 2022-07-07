class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {

        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }

    int path(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int left = max(0, path(root->left, maxi));
        int right = max(0, path(root->right, maxi));

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
    }
};
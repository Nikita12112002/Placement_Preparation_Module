// Recursive

class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {

        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// iterative

class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {

        stack<TreeNode *> st;
        st.push(root);

        if (root == NULL)
            return;

        while (!st.empty())
        {
            auto node = st.top();
            st.pop();

            if (node->right)
                st.push(node->right);

            if (node->left)
                st.push(node->left);

            if (!st.empty())
                node->right = st.top();

            node->left = NULL;
        }
    }
};

// SC:O(1)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *node = root;
        while (node)
        {
            if (node->left)
            {
                TreeNode *pre = node->left;

                while (pre->right)
                {
                    pre = pre->right;
                }

                pre->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }

            node = node->right;
        }
    }
};

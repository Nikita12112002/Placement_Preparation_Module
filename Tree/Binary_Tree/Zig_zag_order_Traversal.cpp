class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> zig;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 1;
        int index;

        if (root == NULL)
            return zig;

        while (!q.empty())
        {
            auto sz = q.size();

            vector<int> zag(sz);

            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();

                if (flag == 1)
                    index = i;
                else
                    index = sz - 1 - i;

                zag[index] = node->val;

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            if (flag == 1)
                flag = 0;
            else
                flag = 1;

            zig.push_back(zag);
        }

        return zig;
    }
};
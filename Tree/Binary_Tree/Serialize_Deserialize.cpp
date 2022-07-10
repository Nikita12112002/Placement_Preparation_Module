class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL)
            return "";
        
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node==NULL)
                s.append("#,");
            else
                s.append(to_string(node->val)+',');
            
            if(node!=NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==NULL)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*>q;
        
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            getline(s,str,',');
            
            if(str=="#")
                node->left=NULL;
            else
            {
                TreeNode * leftNode = new TreeNode(stoi(str));
                q.push(leftNode);
                node->left = leftNode;
            }
            
            getline(s,str,',');
            
            if(str=="#")
                node->right = NULL;
            
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                q.push(rightNode);
                node->right=rightNode;
            }
            
        }
        return root;
    }
};

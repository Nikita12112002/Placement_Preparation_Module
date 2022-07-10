#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

void allTraversal(node* root , vector<int>&pre , vector<int>&in , vector<int>&post)
{
    stack<pair<node*,int>>st;
    st.push({root,1});
    
   
    while(!st.empty())
    {
        auto it =  st.top();
        st.pop();
        
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->left!=NULL)
              st.push({it.first->left,1});
        }
        
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->right!=NULL)
             st.push({it.first->right,1});
        }
        
        else
          post.push_back(it.first->data);
    }
}

int main()
{
   struct node * root = new node(1);
  root -> left = new node(2);
  root -> left -> left = new node(4);
  root -> left -> right = new node(5);
  root -> right = new node(3);
  root -> right -> left = new node(6);
  root -> right -> right = new node(7);

  vector <int> pre, in , post;
  allTraversal(root, pre, in , post);

  cout << "The preorder Traversal is : ";
  for (auto nodeVal: pre) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal: in ) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal: post) {
    cout << nodeVal << " ";
  }
  cout << endl;

  return 0;
}
   

  
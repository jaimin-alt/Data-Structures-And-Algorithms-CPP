 #include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    #define Node TreeNode
    #define null NULL
    void Invert(Node*root)
    {
        if(root==null)
        {
            return;
        }
        swap(root->left,root->right);
        Invert(root->left);
        Invert(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL)
        {
            return NULL;
        }

        Invert(root);
        return root;

    }
};
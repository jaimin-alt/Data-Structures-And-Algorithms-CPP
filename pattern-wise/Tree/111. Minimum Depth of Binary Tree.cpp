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

    // my code

    // int fun(TreeNode*root)
    // {
    //     if(root==NULL)
    //     {
    //         return 0;
    //     }

    //     if(root->left && root->right)
    //     {
    //         int left = fun(root->left);
    //         int right = fun(root->right);
    //         return 1 + min(left,right);
    //     }

    //     if(root->right==NULL)
    //     {
    //         return 1 + fun(root->left);

    //     }
    //     else{
    //         return 1+fun(root->right);
    //     }

    //     return 0;
    // }

    // pratyush code

    int fun(TreeNode*root)
    {
        if(root==NULL) return 0;

        if(root->left==NULL && root->right==NULL) return 1;

        if(root->left==NULL)
        {
            return 1+fun(root->right);
        }
        if(root->right==NULL)
        {
            return 1+fun(root->left);
        }

        return 1 + min(fun(root->left),fun(root->right));
    }
    int minDepth(TreeNode* root) {
        return fun(root);
    }
};
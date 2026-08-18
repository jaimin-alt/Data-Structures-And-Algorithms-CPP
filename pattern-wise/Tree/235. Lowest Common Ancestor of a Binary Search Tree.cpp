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
    TreeNode * ans = NULL;

    void fun(TreeNode *root,TreeNode*p,TreeNode*q)
    {
        if(root==NULL)
        {
            return;
        }

        if(root==p)
        {   
            ans = p;
            return;
        }

        if(root->val<p->val)
        {
            // go to the right side
            fun(root->right,p,q);
        }
        else if(root->val>q->val)
        {
            // go to the left side
            fun(root->left,p,q);
        }
        else
        {
            ans = root;
            
        }

        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return NULL;
        }

        if(p->val<q->val)
        {
            fun(root,p,q);
            return ans;
        }
        else{
            fun(root,q,p);
            
        }

        return ans;
    }
};
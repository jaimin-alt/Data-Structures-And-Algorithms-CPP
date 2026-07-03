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

    #define node TreeNode

    void preOrder(node*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }

        // potane store karvu 
        ans.push_back(root->val);

        // left 
        preOrder(root->left,ans);

        // right
        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;

        preOrder(root,ans);
        return ans;
    }
};

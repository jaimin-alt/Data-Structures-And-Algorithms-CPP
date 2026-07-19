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
    int ans = 0 ;

    int count(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        if(root->left==NULL && root->right==NULL)
        {
            ans++;
            return root->val;
        }

        int left = count(root->left);
        int right = count(root->right);
        int currMax = max(left,right);
        
       if(root->val>=currMax){
           ans++;
           currMax=root->val;
       }

        return currMax;
    }
    int countDominantNodes(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }

        int max = count(root);
        return ans;
    }
};
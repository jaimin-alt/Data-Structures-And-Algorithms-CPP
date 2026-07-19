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
    void sum(TreeNode*root,string & currentNum)
    {   

        if(root==NULL) return;
        currentNum+=('0'+root->val);

        sum(root->left,currentNum);

        sum(root->right,currentNum);


        if(root->left==NULL && root->right==NULL)
        {
            ans+=stoi(currentNum);
        }

        currentNum.pop_back();

        return;

    }
    int sumNumbers(TreeNode* root) {

        string currentNum = "";

        sum(root,currentNum);
        return ans;
    }
};
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
    void sum(TreeNode* root, int targetSum,int currentSum, vector<vector<int>>&ans,vector<int>&path)
    {   if(root==NULL) return;
       
        // take the current element and add it to the path and also give currentsum by adding current element to the next node
        currentSum+=root->val;
        path.push_back(root->val);

        // left node
        sum(root->left,targetSum,currentSum,ans,path);

        // right node
        sum(root->right,targetSum,currentSum,ans,path);

        if(root->left==NULL && root->right==NULL)
        {
            if(currentSum==targetSum)
            {
                ans.push_back(path);
            }
        }
        
        path.pop_back();

        return;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;

        if(root==NULL)
        {
            return ans;
        }

        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            {
                ans.push_back({root->val});
                return ans;
            }

            return ans;
        }

        vector<int>path;
        int currentSum = 0 ;

        sum(root,targetSum,currentSum,ans,path);
        return ans;
    }
};
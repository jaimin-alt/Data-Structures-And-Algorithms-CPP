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

    pair<int,int> average(TreeNode * root)
    {

        if(root==NULL)
        {
            return {0,0};
        }

        int ele = root->val;

    pair<int,int>left = average(root->left);
    pair<int,int>right =  average(root->right);

      //  <int,int> ==>  < sum of subtree , number of nodes in that subtree > 

    int leftSum = left.first;
    int rightSum = right.first;

    int leftNodes = left.second;
    int rightNodes = right.second;

    // calculate current node's average 

    int totalNodes = leftNodes + rightNodes + 1;

    int totalSum = leftSum + rightSum + ele ;

    int avg = totalSum/totalNodes;

    if(avg==ele)
    {
        ans++;
    }

    return {totalSum,totalNodes};

    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> p = average(root);

        return ans;
    }
};
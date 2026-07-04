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

    Node * ans = NULL;
    int countAncestor(Node * root,Node  *p,Node * q)
    {

        if(root==NULL) return 0;
        int left = countAncestor(root->left,p,q);
        int right = countAncestor(root->right,p,q);
        int self =  0;

        if((root==p) || (root==q))
        {
            self = 1;
        }

        int total = left+right+self;

        if(total==2 && ans==NULL)
        {
            ans = root;
        }

        return total;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int count = countAncestor(root,p,q);
        return ans;
    }
};
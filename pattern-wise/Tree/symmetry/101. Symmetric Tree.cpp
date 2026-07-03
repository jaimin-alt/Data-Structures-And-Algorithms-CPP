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
    bool symmetric(Node * root1, Node * root2)
    {
        if(root1==null && root2==null)
        {
            return true;
        }
        if(root1==null || root2==null)
        {
            return false;
        }
        if(root1->val!=root2->val)
        {
            return false;
        }

        // tree1 no left and trr2 no right 

        bool r1 = symmetric(root1->left,root2->right);

        // tree1 no right and tree2 no left 

        bool r2 = symmetric(root1->right,root2->left);

        return (r1&&r2);


    }
    bool isSymmetric(TreeNode* root) {
        
      return symmetric(root->left,root->right);

    }
};
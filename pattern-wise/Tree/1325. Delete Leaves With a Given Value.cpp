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
    void remove(TreeNode*root,TreeNode*parent,int target,bool leftChild)
    {
        if(root==NULL)
        {
            return ;
        }

        // call left with parent
        remove(root->left,root,target,1);

        // call right with parent

        remove(root->right,root,target,0);

        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==target)
            {
                if(parent==NULL)
                {
                    return ;
                }
                else{
                    if(leftChild)
                    {
                        parent->left=NULL;
                    }
                    else{
                        parent->right=NULL;

                    }
                }
            }
        }

        return ;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove(root,NULL,target,0);
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==target)
            {   
              
                return NULL;
            }
        }
        return root;
    }
};
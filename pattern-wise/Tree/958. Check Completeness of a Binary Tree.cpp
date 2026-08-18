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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;

        queue<TreeNode*>q;

        q.push(root);
        bool nullSeen = false;
        while(!q.empty())
        {
            TreeNode*t = q.front();
            q.pop();

            if(t!=NULL && nullSeen==true )
            {
                return false;
            }
            if(t==NULL)
            {
                if(nullSeen==false)
                {
                    nullSeen = true;
                }

                continue;

            }

            q.push(t->left);
            q.push(t->right);
        }

        return true;
    }
};
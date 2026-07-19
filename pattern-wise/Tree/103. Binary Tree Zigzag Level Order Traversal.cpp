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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back({root->val});

            return ans;
        }

        queue<TreeNode*>q;

        q.push(root);

        bool left_to_right = true;

        while(!q.empty())
        {
            int s = q.size();

            vector<int>temp(s);

            int k;

            if(left_to_right)
            {
                k = 0 ;
            }
            else{
                k=s-1;
            }

            while(s--)
            {
                TreeNode * t = q.front();
                q.pop();

                if(left_to_right)
                {
                    temp[k] = t->val;
                    k++;
                }
                else{
                    temp[k] = t->val;
                    k--;
                }

                // now push the childrens

                if(t->left!=NULL)
                {
                    q.push(t->left);

                }

                if(t->right!=NULL)
                {
                    q.push(t->right);
                }
            }

            left_to_right = !left_to_right;
            ans.push_back(temp);
        }

        return ans;

    }
};
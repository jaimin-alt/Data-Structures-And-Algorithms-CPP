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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;
        queue<Node*>q;

        q.push(root);

        while(!q.empty())
        {
            vector<int>temp;

            int levelsize = q.size();

            while(levelsize--)
            {
                Node*t = q.front();
                q.pop();
                temp.push_back(t->val);
                
                if(t->left!=NULL)
                {
                    q.push(t->left);
                }
                if(t->right!=NULL)
                {
                    q.push(t->right);

                }
            }

            ans.push_back(temp);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define node TreeNode
    #define null NULL
    vector<vector<int>> levelOrder(TreeNode* root) {

         vector<vector<int>>ans;
         if(!root)
         {
            return ans;
         }
        queue<node*> q;
        q.push(root);
       
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int>tmp;

            while(levelSize--)
            {
                node * t = q.front();
                q.pop();
                tmp.push_back(t->val);

                if(t->left!=null)
                {
                    q.push(t->left);
                }
                if(t->right!=null)
                {
                    q.push(t->right);
                }
            }

            ans.push_back(tmp);
        }

        return ans ;
    }
};
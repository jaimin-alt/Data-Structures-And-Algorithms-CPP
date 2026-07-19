 #include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;

        // if only one root and it doesnot have any child
        if((root->children).size()==0)
        {
            ans.push_back({root->val});
            return ans;
        }

        // same as bfs 
        // here we are given neighbours in the form of vector of nodes pointer 
        // like adjacency list

        queue<Node*>q;

        q.push(root);

        while(!q.empty())
        {
            int s = q.size();
            vector<int>temp;
            while(s--)
            {
                Node * t = q.front();
                q.pop();

                temp.push_back(t->val);

                // now push the neighbours or childerns

                vector<Node*> children= t->children;

                // now iterate through this 
                if(children.size()>0)
                {
                     for(Node * child : children)
                     {
                        q.push(child);
                     }
                }
               
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
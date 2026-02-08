#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next==NULL)
        {
            vector<int>ans(1,0);
            return ans;
        }
        stack<pair<int,ListNode*>>st;

        ListNode * temp = head;
        int count = 0 ;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }

        vector<int>ans(count,0);
        temp = head;
        int i = 0 ;
        while(temp!=NULL)
        {   
            while(!st.empty() && (temp->val > ((st.top()).second)->val))
            {
                ans[(st.top()).first] = temp->val;
                st.pop();
            }
            st.push({i++,temp});
            temp = temp->next;
        }

        return ans;
    }
};
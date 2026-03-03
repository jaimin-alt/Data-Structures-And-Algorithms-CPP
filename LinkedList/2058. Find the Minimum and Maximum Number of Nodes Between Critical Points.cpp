 #include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // it is sure that first and last node can never be critical points

        if(head->next->next==NULL) {
            vector<int>ans = {-1,-1};
            return ans;
        }

        int ind= 2;
        ListNode* curr = head->next,*prev = head,*nextnode=head->next->next;
        vector<int>temp;

        while(nextnode)
        {   
            if(((curr->val)>(prev->val) && (curr->val)>(nextnode->val)) || 
            ((curr->val)<(prev->val) && (curr->val)<(nextnode->val))
            )
            {
            temp.push_back(ind);
            }

            ind++;
            prev = curr;
            curr=nextnode;
            nextnode=nextnode->next;
        }

        if(temp.size()<2)
        {
            vector<int>ans={-1,-1};
            return ans;
        }
        if(temp.size()==2)
        {
            vector<int>ans(2);
            ans[0] =abs(temp[0]-temp[1]);
            ans[1] = ans[0];
            return ans;
        }

        int mindistance = INT_MAX,maxdistance=0;

        for(int i=1;i<temp.size();i++)
        {
            mindistance = min(mindistance,temp[i]-temp[i-1]);
        }

        maxdistance = temp[temp.size()-1]-temp[0];

        vector<int>ans(2);
        ans[0] = mindistance;
        ans[1] = maxdistance;

        return ans;
       


    }
};
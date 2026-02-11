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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        

        ListNode* curr = head;
        ListNode * prev = curr;
        set<int>s(nums.begin(),nums.end());
        while(curr)
        {   bool can_delete = false;
           if(s.find(curr->val)!=s.end())
            {
                  can_delete = true;
                    if(curr==head)
                    {   
                        ListNode*temp=curr;
                        curr=curr->next;
                        temp->next==NULL;
                        prev=curr;
                        head = curr;
                    }
                    else{
                        prev->next = curr->next;
                        curr->next=NULL;
                        curr=prev->next;
                    }
            }

            if(!can_delete)
            {   prev = curr;
                curr=curr->next;
            }

        }

        return head;
    }
};
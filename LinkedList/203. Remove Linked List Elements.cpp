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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        if(head->next==NULL)
        {
            if(head->val==val) return NULL;
            return head;
        }

        ListNode*new_linked = new ListNode(0);
        ListNode*temp2 = new_linked;


        ListNode*temp = head;

        while(temp)
        {
            if(temp->val!=val)
            {
                temp2->next = new ListNode(temp->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        return new_linked->next;

    }
};
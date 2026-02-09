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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        // if( head==NULL || head->next==NULL ) return NULL;
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        if( head->next==head ||  head->next->next==head) return head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        if(slow!=fast) return NULL;

        ListNode * temp = head;
        while(temp!=slow)
        {
           
            slow=slow->next;
            temp=temp->next;
        }
        return slow;
    }
};
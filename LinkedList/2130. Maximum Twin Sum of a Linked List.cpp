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
    int pairSum(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head->next;

        if(fast->next==NULL) return slow->val+fast->val;

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode * second = slow->next;
        slow->next=NULL;
        ListNode * first = head;

        // reverse the second linkedlist

        ListNode * prev = NULL;
        ListNode * curr = second;
        ListNode * next = second;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev  = curr;
            curr = next;
        }

        second = prev ; 

        // do the sum of first and second element wise and take maximum ; 
        int maxi =INT_MIN;
        while(first)
        {
            maxi = max(maxi,first->val+second->val);
            first = first->next;
            second = second->next;
        }

        return maxi;

    }
};
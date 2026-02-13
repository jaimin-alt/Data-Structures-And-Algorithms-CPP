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
    ListNode* doubleIt(ListNode* head) {

        if(head==NULL) return NULL;
        if(head->next==NULL && head->val==0) return head;
        if(head->next==NULL){
            int x = (head->val*2);

            if(x<10)
            {
                head->val = x;
                return head;
            }
            head->val = x/10;
            head->next = new ListNode(x%10);
            return head;
    
        }

        // first of all reverse the linked list 
        ListNode * curr= head;
        ListNode * prev=  NULL;
        ListNode * next = head;

        while(curr)
        {
            next =  curr->next;
            curr->next =  prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        // now do multiplication with 2

        int carry = 0 ;
        curr = head;
        prev = head;

        while(curr)
        {
            int x = (curr->val*2 + carry);
            curr->val = x%10;
            carry = x/10;
            prev = curr;
            curr=curr->next;
        }

        if(carry)
        {
            prev->next = new ListNode(carry);
        }

        // again reverse it so the answer is in original linkedlist form 
        curr = head;
        prev = NULL;
        next = head;
          while(curr)
        {
            next =  curr->next;
            curr->next =  prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        return head;

    }
};
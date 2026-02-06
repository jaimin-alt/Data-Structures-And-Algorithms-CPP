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
    ListNode* removeNodes(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode*next = head;
        if(head==NULL || head->next==NULL) return head;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        int maxi= INT_MIN;
        curr = head;
        prev = head;
        while(curr!=NULL)
        {   
            if(curr->val>=maxi)
            {
                maxi = curr->val;
                 prev = curr;
                 curr = curr->next;
                
            }
            else{
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
            }
        }


        //again reverse 

        prev = NULL;
        curr = head;
        next = head;

         while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        return head;
    }
};
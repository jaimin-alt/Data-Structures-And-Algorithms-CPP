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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        if(head->next->next==NULL) 
        {
            if(head->val==head->next->val) return true;
            return false;

        }

        int size= 0 ;
        ListNode * temp = head;

        while(temp)
        {
            temp = temp->next;
            size++;
        }

        // if(size==3)
        // {
        //     if(head->val==head->next->next->val)
        //     {
        //         return true;
        //     }
        //     return false;
        // }

        int x= size/2;

        temp = head;
        x--;

        while(x--)
        {
            temp=temp->next;
        }

        ListNode*list2=NULL;
        
        if(size%2==0)
        {
            
        list2 = temp->next;
        }
        else{      
        list2 = temp->next->next;
        temp->next->next=NULL;

        }

        temp->next=NULL;
        ListNode*list1 = head;

        //  reverse the second list

        ListNode*prev=NULL;
        ListNode*curr = list2;
        
        while(curr)
        {
            ListNode * next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
        list2 = prev;

        // compare 

        ListNode*temp1 = list1,*temp2 = list2;

        while(temp1)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return true;




        
    }
};
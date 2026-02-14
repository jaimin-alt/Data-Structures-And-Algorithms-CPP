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

    int calculate(ListNode*&ans,ListNode*curr1,ListNode*curr2)
    {
        if(curr1==NULL)
        {
            return 0;

        }

        int sum = curr1->val+curr2->val + calculate(ans,curr1->next,curr2->next);

        ans->next = new ListNode(sum%10);
        ans = ans->next;
        return sum/10;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0) return l2;
        if(l2->val==0) return l1;

        int n=0;
        int m=0;
        ListNode  * temp = l1;

        while(temp)
        {
            n++;
            temp=temp->next;
        }

        temp=l2;

        while(temp)
        {
            m++;
            temp=temp->next;
        }

        if(n<m)
        {
            int diff = m-n;
            ListNode*fake_head=new ListNode(0);
            ListNode*curr = fake_head;
            diff--;
            while(diff--)
            {
             curr->next = new ListNode(0);
             curr=curr->next;
            }
            curr->next = l1;
            l1=fake_head;
            
        }
        else if (m<n)
        {
            int diff = n-m;
            ListNode*fake_head=new ListNode(0);
            ListNode*curr = fake_head;
            diff--;
            while(diff--)
            {
             curr->next = new ListNode(0);
             curr=curr->next;
            }
            curr->next = l2;
            l2=fake_head;
        }

        ListNode*curr1=l1;
        ListNode*curr2=l2;
        ListNode*ans=new ListNode(0);
        ListNode*ans_head = ans;

        int carry = calculate(ans,curr1,curr2);
        if(carry)
        {
            ans->next = new ListNode(carry);
        }

        ans = ans_head;
        ans_head = ans_head->next;
        ans->next=NULL;

        // now reversen the answer 

        ListNode * curr = ans_head;
        ListNode* next = curr;
        ListNode*prev = NULL;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ans_head = prev;

        return ans_head;

    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// LeetCode 143: Reorder list
// Difficulty: medium
// Approach: stack
// Time: O(n), Space: O(n)
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
    void reorderList(ListNode* head) {
        int n=0;
        if(head==NULL || head->next==NULL) return;


        ListNode * temp = head;

        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }

        if(n==2) return;

        stack<ListNode*>st;

        temp=head;

        while(temp!=NULL)
        {
            st.push(temp);
            temp=temp->next;
        }

        n/=2;
        temp=head;
        ListNode*temp_next = temp;
        while(n--)
        {   
            temp_next = temp->next;
           
            ListNode * last = st.top();
             temp->next = last;
             last->next = temp_next;
            st.pop();
            temp = temp_next;
        }
        temp->next=NULL;
        return;
    }
};
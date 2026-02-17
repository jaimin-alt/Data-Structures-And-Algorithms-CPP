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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if size is 0 or 1 
        if(head==NULL || head->next==NULL) return head;
        // if size is 2
        if(head->next->next==NULL)
        {
            if(head->val==head->next->val) return NULL;
            return head;
        }
        // if size is greater than or equal to 3

       stack<ListNode*>st;
       ListNode * temp= head;

       while(temp)
       {
        if(st.empty())
        {
            st.push(temp);
            temp=temp->next;
        }
        else if(st.top()->val==temp->val)
        {
            while(temp && st.top()->val==temp->val)
            {
                temp=temp->next;
            }
            st.pop();

            if(st.empty())
            {
                head = temp;
            }
            else{
                st.top()->next = temp;
            }

        }
        else{
            st.push(temp);
            temp=temp->next;
        }
       }

       return head;

    }
};
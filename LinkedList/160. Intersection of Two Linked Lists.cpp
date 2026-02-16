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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp = headA;
        int a = 0 ;
        int b =  0;

        while(temp)
        {
            temp=temp->next;
            a++;
        }

        temp = headB;

        while(temp)
        {
            temp=temp->next;
            b++;
        }
        
        int diff = abs(a-b);

        if(a>b)
        {
            // list a moti chhe 

            temp = headA;

            while(diff--)
            {
                temp=temp->next;
            }

            ListNode * temp2 = headB;

            while(temp!=NULL && temp2!=NULL)
            {
                if(temp==temp2)
                {
                    return temp;
                }
                temp = temp->next;
                temp2=temp2->next;
            }
        }
        else{
            // list b moti chhe 

            temp = headB;

            while(diff--)
            {
                temp=temp->next;
            }

            ListNode * temp2 = headA;

            while(temp!=NULL && temp2!=NULL)
            {
                if(temp==temp2)
                {
                    return temp;
                }
                temp = temp->next;
                temp2=temp2->next;
            }


        }

        return NULL;



       

    }
};
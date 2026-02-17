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

class MyLinkedList {
ListNode* head ;
ListNode * tail;
int size;
public:
    MyLinkedList() {
        head = NULL;
        tail=NULL;
        size=0;
    }
    
    int get(int index) {
        if(size==0 || index<0 || index>=size) return -1;
        ListNode * temp = head;
        while(index--)
        {
            temp = temp->next;

        }

        return temp->val;

    }
    
    void addAtHead(int val) {
        if(size==0)
        {
            head = new ListNode(val);
            tail = head;
        }
        else{
            ListNode * temp = new ListNode(val);
            temp->next = head;
            head = temp;
        }
        size++;
        return;
        
    }
    
    void addAtTail(int val) {
        if(size==0)
        {
            head = new ListNode(val);
            tail = head;
            size++;
            return ;
        }

        tail->next = new ListNode(val);
        tail = tail->next;
        size++;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;

        if(size==0)
        {
             head = new ListNode(val);
            tail = head;
            size++;
            return;

        }

        if(index==0)
        {
            addAtHead(val);
            return;
        }

        if(index==size)
        {
            addAtTail(val);
            return;
        }

        ListNode * temp = head;
        index--;
        while(index--)
        {
            temp=temp->next;
        }

        ListNode * newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return;
        
    }
    
    void deleteAtIndex(int index) {
        if(size==0 || index<0 || index>=size)
        {
            return;
        }

        if(size==1)
        {
            head=NULL;
            tail=NULL;
            size--;
            return;
        }

    //    head delete 

        if(index==0)
        {  
            ListNode *temp = head;
            head = head->next;
            temp->next= NULL;
            delete temp;
            size--;
            return;
        }

        // tail delete 

        if(index==size-1)
        {
            ListNode * temp=head;

            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            tail = temp;
            size--;
            return;
        }

        // any index

        ListNode * temp = head;
        ListNode * prev = head;
        
        while(index--)
        {
            prev = temp;
            temp=temp->next;
        }

        prev->next = temp->next;
        temp->next=NULL;
        delete temp;
        size--;
        return;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
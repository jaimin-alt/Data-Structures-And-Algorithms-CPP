 #include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int val;
        Node * prev;
        Node * next;

        Node(int x)
        {
            val = x;
            next = NULL;
            prev=NULL;

        }
};

class MyCircularDeque {
    int capacity;
    int size;
    Node * head;
    Node * tail;
public:
    MyCircularDeque(int k) {
        capacity = k;
        size = 0 ;
        head = NULL;
        tail = NULL;

    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            head = new Node(value);
            tail=head;
        }
        else{
            Node * temp  = new Node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;

        }

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            tail = new Node(value);
            head = tail;
        }
        else{
            tail->next = new Node(value);
            tail->next->prev = tail;
            tail=tail->next;
        }

        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }

        if(size==1)
        {
            head=NULL;
            tail= NULL;
            size--;
            return true;
        }

        
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        head->prev = NULL;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }

        if(size==1)
        {
            head=NULL;
            tail= NULL;
            size--;
            return true;
        }

        tail = tail->prev;
        tail->next=NULL;
        size--;
        return true;

        
    }
    
    int getFront() {
        if(isEmpty())
        {
            return -1;
        }
        return head->val;
    }
    
    int getRear() {
        if(isEmpty())
        {
            return -1;
        }
        return tail->val;
    }
    
    bool isEmpty() {
        if(size==0 && head==NULL && tail==NULL)
        {
            return true;
        }
        return false;

    }
    
    bool isFull() {

        if(size<capacity)
        {
            return false;
        }
       return true;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
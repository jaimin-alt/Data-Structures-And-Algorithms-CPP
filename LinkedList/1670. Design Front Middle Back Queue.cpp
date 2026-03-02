 #include <bits/stdc++.h>
using namespace std;


class Node{
    public: 
        int val;
        Node * next;
        Node*prev;

        Node(int x)
        {
            this->val = x;
            next = NULL;
            prev = NULL;

        }
    
};

class FrontMiddleBackQueue {
   Node * head;
   Node * tail;
   Node * middle;
   int size ; 

public:
    FrontMiddleBackQueue() {
        head = NULL;
        tail = NULL;
        middle = NULL;
        size = 0 ;

    }
    
    void pushFront(int val) {
        if(size==0)
        {
            head =new Node(val);
            tail = head;
            middle = head;
            size++;
            return;
        }
        
        if(size==1)
        {
            
            Node * temp = new Node(val);
            temp->next = middle;
            middle->prev = temp;
            middle = temp;

            head = middle;
            size++;
            return;

        }

        if(size%2==0)
        {
            Node * temp = new Node(val);
            temp->next = head;
            head->prev =temp;
            head = temp;
            size++;
            return;
        }
        else{
            Node * temp = new Node(val);
            temp->next = head;
            head->prev = temp;
            head = temp;
            middle = middle->prev;
            size++;
            return;
        }

    }
    
    void pushMiddle(int val) {
      if(size==0)
        {
            head =new Node(val);
            tail = head;
            middle = head;
            size++;
            return;
        }
        if(size==1)
        {
            
            Node * temp = new Node(val);
            temp->next = middle;
            middle->prev = temp;
            middle = temp;

            head = middle;
            size++;
            return;

        }
        if(size%2==0)
        {
            Node * temp = new Node(val);
            temp->next = middle->next;
            temp->prev = middle;
            middle->next->prev = temp;
            middle->next = temp;
            middle =temp;

        }
        else{
            Node * temp = new Node(val);
            temp->next = middle;
            temp->prev = middle->prev;
            middle->prev->next =temp;
            middle->prev = temp;
            middle = temp;

        }
        size++;
        return;
        
    }
    
    void pushBack(int val) {
        if(size==0)
        {
            head =new Node(val);
            tail = head;
            middle = head;
            size++;
            return;
        }
        if(size%2==0)
        {
            tail->next = new Node(val);
            tail->next->prev = tail;
            tail = tail->next;
            middle = middle->next;
            size++;
            return;

        }
        tail->next = new Node(val);
            tail->next->prev = tail;
            tail = tail->next;
            size++;
            return ;
       

        
    }
    
    int popFront() {
        if(size==0)
        {
            return -1;
        }
        int val = head->val;
        if(size==1)
        {
            head=NULL;
            tail=NULL;
            middle=NULL;
            size--;
            return val;

        }
        if(size==2)
        {
            middle = middle->next;
            middle->prev = NULL;
            head = middle;
            size--;
            return val;

        }
        if(size%2==0)
        {
            Node * temp = head;
            head=head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            size--;
            middle=middle->next;
            return val;
        }
        Node * temp = head;
            head=head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
            size--;
            return val;


        
    }
    
    int popMiddle() {
        if(size==0)
        {
            return -1;
        }
        int val = middle->val;
        if(size==1)
        {
            head=NULL;
            middle=NULL;
            tail=NULL;
            size--;
            return val;
        
        }
        if(size==2)
        {
            middle =middle->next;
            head->next = NULL;

            head=middle;
            head->prev = NULL;
            size--;
            return val;;

            
        }
        if(size%2==0)
        {
            Node * temp = middle;
            val = middle->val;
            middle = middle->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            size--;
            return val;
        }
            Node * temp = middle;
            val=middle->val;
            middle = middle->prev;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            size--;
            return val;

    }
    
    int popBack() {
        if(size==0)
        {
            return -1;

        }
        
        int val = tail->val;
        if(size==1)
        {
            head=NULL;
            middle=NULL;
            tail=NULL;
            size--;
            return val;
        }
        if(size%2==0)
        {
            tail=tail->prev;
            tail->next = NULL;
            size--;
            return val;
        }
        tail=tail->prev;
            tail->next = NULL;
            size--;
            middle=middle->prev;
            return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
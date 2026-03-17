
 #include <bits/stdc++.h>
using namespace std;


class Page{

    public:
        string name;
        Page*prev;
        Page*next;

        Page(string name){
            this->name = name;
            prev = NULL;
            next = NULL;

        }
};


class BrowserHistory {
    Page* head;
    Page * current;
public:
    BrowserHistory(string homepage) {
        head = new Page(homepage);
        current = head;
    }
    
    void visit(string url) {

        if(current->next==NULL)
        {
            current->next = new Page(url);
        current->next->prev = current;
        current = current->next;

        }
        else{
            current->next==NULL;
            current->next = new Page(url);
        current->next->prev = current;
        current = current->next;
        }
        
    }
    
    string back(int steps) {
        while(steps-- && current->prev!=NULL)
        {
            current = current->prev;
        }

        return current->name;
    }
    
    string forward(int steps) {
        while(steps-- && current->next!=NULL)
        {
            current = current->next;
        }

        return current->name;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
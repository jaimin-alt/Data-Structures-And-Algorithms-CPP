#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q1;
    
    MyStack() {
        
    }
    
    bool empty() {
        return q1.empty();
    }

    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
        int x = q1.size()-1;

        while(x--)
        {
            q1.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        if(empty()) return -1;
        return q1.back();
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
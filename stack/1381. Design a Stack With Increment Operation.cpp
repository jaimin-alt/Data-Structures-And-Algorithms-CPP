#include<bits/stdc++.h>
using namespace std;


class CustomStack {
    vector<int>st;
    int top;
    int maxi;
public:
    CustomStack(int maxSize) {
        this->maxi=maxSize;
        top=-1;
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(top+1==maxi)
        {
            return;

        }

        st[++top] = x;
        return;
        
    }
    
    int pop() {
        if(top==-1)
        {
            return -1;

        }
        return st[top--];       
    }
    
    void increment(int k, int val) {

        if(k>(top+1))
        {
            for(int i =0;i<=top;i++)
            {
                st[i]+=val;
            }

        }
        else{
            for(int i=0;i<k;i++)
            {
                st[i]+=val;
            }
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
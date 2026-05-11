

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int sum_sq_digits(int n)
    {
        int sum  = 0 ;
        while(n)
        {
            int rem = n%10;
            n/=10;
            sum+=(rem*rem);
        }
        return sum;
    }
    bool isHappy(int n) {

        int slow = n,fast = n;
        if(sum_sq_digits(n)==1)
        {
            return true;
        }
        while(fast!=1)
        {
            slow = sum_sq_digits(slow);
            fast = sum_sq_digits(sum_sq_digits(fast));
            if(slow==fast) return false;
        }

        return true;
        
    }
};
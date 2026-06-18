
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfElementLessThanGuess(int m,int n,int guess)
    {
        // starting from bottom left corner
        // since it is one indexed : i = m ,j = 1
        int count = 0 ;

        int i=m,j = 1;

        while(i>0 && j<=n)
        {
            int number = i*j;
            if(number<=guess)
            {
                count+=i;
                j++;
            }
            else{
                i--;
            }
        }

        return count;

    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int ans = -1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(numberOfElementLessThanGuess(m,n,mid)>=k)
            {
                // this mid can be the answer but it can present in matrix or not 
                // so for that store the answer and go to the left side

                ans = mid;
                high = mid-1;

            }
            else{
                // if number of element less than guess is less than k that means if k = 6 and guess = 5 , means number of element less than 5 will be less than 6 means 5 can be at the at max 5th position can never be the 6 the position so we have to go to the right side
                low = mid+1;
            }
        }
        return ans;
    }
};
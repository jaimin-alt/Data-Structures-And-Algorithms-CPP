#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfElementsLessThanGuess(vector<vector<int>>&a,int n,int m,int guess)
    {
        int count = 0 ;
        // starting from the bottom left corner
        int i = n-1;
        int j  = 0;

        while(i>=0 && j<m)
        {
            if(a[i][j]<=guess)
            {
                // if number is less than k means all the numbers above it in that column will also be less than the k so we have to add all the elements above current element and also current element ,  and move to the right side 
                count+=i+1;
                j++;
            }
            else{
                // if number is greater than k means all the elements after that element in that row will always be the greater than the k so we have to go to the up 
                i--;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = -1;
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(numberOfElementsLessThanGuess(matrix,n,m,mid)>=k)
            {  // if number of elements less than guess is greater then or equal to k , then mid can be the answer so store it, and we dont know wether the mid exist in matrix or not so for that's why we go t left side

                ans=mid;
                high = mid-1;

            }
            else
            {
                // if mid cannot be the answer then the numbers less then mid can never be ....so go to the right side
                low = mid+1;
            }
        }

        return ans;
    }
};
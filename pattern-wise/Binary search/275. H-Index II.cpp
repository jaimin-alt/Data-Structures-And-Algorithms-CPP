#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0 ;
        int low = 0;
        int high= n-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int numberOfPapersHavingCitationsAtLeastMid = n-mid;
            if(numberOfPapersHavingCitationsAtLeastMid <= citations[mid])
            {
                // store the answer and go to the left
                ans = n-mid;
                high = mid-1;
            }
            else{
                // go to the right 
                low = mid+1;

            }
        }

        return ans;
    }
};
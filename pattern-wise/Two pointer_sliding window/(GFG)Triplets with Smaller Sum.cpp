

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int count = 0 ;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-2;i++)
        {
            int left = i+1;
            int right = n-1;
            
            
            while(left<right)
            {
                int x =arr[i]+ arr[left]+arr[right];
                
                if(x<sum)
                {
                    count+=(right-left);
                    left++;
                }
                else{
                    right--;
                }
                
            }
        }
        
        return count;
    }
};
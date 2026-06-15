#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0,mid,end =(n*m)-1;
        int row,col;

        while(start<=end)
        {
            mid = start + (end-start)/2;
            row = mid/m;
            col = mid%m;

            if(matrix[row][col]==target) return 1;
            else if(matrix[row][col]<target) start = mid + 1;
            else end = mid-1;
        }
        return 0;
    }
};
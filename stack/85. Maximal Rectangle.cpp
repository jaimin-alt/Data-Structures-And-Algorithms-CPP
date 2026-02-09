#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;

        // finding next smallest element on right side 

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (heights[i]<heights[st.top()]))
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // empty the stack  

        while(!st.empty())
        {
            right[st.top()]=n;
            st.pop();
        }


        // finding next smallest element for left side 

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && (heights[i]<heights[st.top()]))
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);

        }


        // empty the stack  

        while(!st.empty())
        {
            left[st.top()] = -1;
            st.pop();
        }

        // calculate the mximum area  

        int ans = 0 ;

        for(int i =0;i<n;i++)
        {
            ans = max(ans,heights[i]*(right[i]-left[i]-1));
        }

        return ans;


    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>heights(col,0);
        int area = 0 ;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                heights[j] = matrix[i][j]=='0'? 0 : heights[j]+1;
            }

                area = max(area,largestRectangleArea(heights));
        }
        return area;
    }
};
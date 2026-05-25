
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            if (onedelete == INT_MIN) {
                onedelete = max(arr[i], nodelete);

            } else {
                onedelete = max(onedelete + arr[i], nodelete);
            }

            nodelete = max(nodelete + arr[i], arr[i]);
            result = max(result, max(onedelete, nodelete));
        }

        return result;
    }
};


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowsum(n), colsum(m);
        long long totalsum = 0;

        // Row sums + total sum
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
                totalsum += grid[i][j];
            }
            rowsum[i] = sum;
        }

        // Column sums
        for(int j = 0; j < m; j++) {
            long long sum = 0;
            for(int i = 0; i < n; i++) {
                sum += grid[i][j];
            }
            colsum[j] = sum;
        }

        // Check row partition
        long long prefix = 0;
        for(int i = 0; i < n - 1; i++) {
            prefix += rowsum[i];
            if(prefix == totalsum - prefix) return true;
        }

        // Check column partition
        prefix = 0;
        for(int j = 0; j < m - 1; j++) {
            prefix += colsum[j];
            if(prefix == totalsum - prefix) return true;
        }

        return false;
    }
};
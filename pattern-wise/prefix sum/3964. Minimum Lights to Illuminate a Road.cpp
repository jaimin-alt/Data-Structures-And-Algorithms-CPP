

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        // Mark illuminated ranges using difference array
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int start = max(0, i - lights[i]);
                int end = min(n - 1, i + lights[i]);

                diff[start]++;

                if (end + 1 < n)
                    diff[end + 1]--;
            }
        }

        vector<bool> illuminated(n, false);

        int coverage = 0;
        for (int i = 0; i < n; i++) {
            coverage += diff[i];
            illuminated[i] = (coverage > 0);
        }

        int ans = 0;
        int continuous = 0;

        for (int i = 0; i < n; i++) {
            if (!illuminated[i]) {
                continuous++;
            } else {
                if (continuous > 0) {
                    ans += (continuous + 2) / 3; // ceil(continuous / 3)
                    continuous = 0;
                }
            }
        }

        if (continuous > 0) {
            ans += (continuous + 2) / 3;
        }

        return ans;
    }
};
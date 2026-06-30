
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<char, int> &a, pair<char, int> &b)
        {
            // maxheap so use less operator
            if (a.second != b.second)
            {
                return a.second < b.second;
            }

            return a.first < b.first;
        }
    };

    int leastInterval(vector<char> &tasks, int n)
    {
        int s = tasks.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> next_free_seat;

        for (char c : tasks)
        {
            freq[c]++;
            next_free_seat[c] = 1;
        }

        priority_queue<
            pair<char, int>,
            vector<pair<char, int>>,
            cmp>
            maxHeap;

        // now all char and freq are pushed into max heap
        for (auto &p : freq)
        {
            maxHeap.push(p);
        }
        int seat = 1;
        while (!maxHeap.empty())
        {
            vector<pair<char, int>> pulled;

            while (!maxHeap.empty())
            {
                pair<char, int> p = maxHeap.top();
                maxHeap.pop();

                char c = p.first;
                int freq = p.second;

                if (next_free_seat[c] <= seat)
                {
                    p.second--;
                    if (p.second > 0)
                    {
                        maxHeap.push(p);
                    }
                    next_free_seat[c] = seat + n + 1;

                    break;
                }
                else
                {
                    pulled.push_back(p);
                }
            }

            for (auto &p : pulled)
            {
                maxHeap.push(p);
            }

            seat++;
        }

        return seat - 1;
    }
};
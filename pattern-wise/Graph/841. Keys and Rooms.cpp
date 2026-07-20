#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool>visited(n,0);

        //apply bfs at 0
        
        queue<int>q;
        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();

            vector<int>neighbours = rooms[currentNode];

            for(int i = 0 ;i<neighbours.size();i++)
            {
                int neighbour = rooms[currentNode][i];

                if(visited[neighbour]==false)
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }


        }

        // check if all are visited or not 

        for(int i = 0 ;i <n;i++)
        {
            if( visited[i] == false){
                return false;
            }
        }

        return true;
    }
};
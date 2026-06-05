#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0,0});

        int mod = 1e9 + 7;

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto next : adj[node]){
                int v = next.first;
                long long w = next.second;
                
                //first time 
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                }//repeated
                else if(d + w == dist[v]){
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};

int main() {
    Solution sol;

    int n = 7;

    vector<vector<int>> roads = {
        {0,6,7},
        {0,1,2},
        {1,2,3},
        {1,3,3},
        {6,3,3},
        {3,5,1},
        {6,5,1},
        {2,5,1},
        {0,4,5},
        {4,6,2}
    };

    cout << "Number of shortest paths = "
         << sol.countPaths(n, roads)
         << endl;

    return 0;
}
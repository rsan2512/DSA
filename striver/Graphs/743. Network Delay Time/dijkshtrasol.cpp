#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, 1e9);
        vector<pair<int,int>> adj[n + 1];

        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int dt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dt > dist[node]) continue;

            for(auto next : adj[node]) {
                int v = next.first;
                int w = next.second;

                if(w + dt < dist[v]) {
                    dist[v] = w + dt;
                    pq.push({dist[v], v});
                }
            }
        }

        int mx = *max_element(dist.begin() + 1, dist.end());
        return mx == 1e9 ? -1 : mx;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;

    cout << "Network Delay Time = "
         << sol.networkDelayTime(times, n, k)
         << endl;

    return 0;
}
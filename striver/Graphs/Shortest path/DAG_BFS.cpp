#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(N);
        vector<int> indeg(N, 0);

        // Build graph
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            indeg[v]++;
        }

        // Kahn's topo sort
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (auto [v, w] : adj[node]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        // Distance array
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Relax edges in topo order
        for (auto node : topo) {
            if (dist[node] != 1e9) {
                for (auto [v, w] : adj[node]) {
                    if (dist[v] > dist[node] + w) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        // Replace unreachable with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
int main() {
    int N = 6;
    int M = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 5, 4},
        {5, 3, 1}
    };

    Solution obj;
    vector<int> result = obj.shortestPath(N, M, edges);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
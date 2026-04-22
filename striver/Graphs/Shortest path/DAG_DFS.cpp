#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs_topo(int node, vector<vector<pair<int,int>>>& adj,
                  vector<bool>& vis, stack<int>& st) {

        vis[node] = true;

        for (auto [x, w] : adj[node]) {
            if (!vis[x]) {
                dfs_topo(x, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(N);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // Topo sort
        vector<bool> vis(N, false);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs_topo(i, adj, vis, st);
            }
        }

        // Distance array
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Relax edges in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

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
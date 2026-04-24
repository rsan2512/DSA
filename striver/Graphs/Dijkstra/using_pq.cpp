#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {

    vector<vector<pair<int,int>>> adj(V);

    // Build graph (UNDIRECTED for your example)
    for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this if directed
    }

    vector<int> dist(V, 1e9);
    dist[S] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, S});

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto [adjNode, wt] : adj[node]){
            if(d + wt < dist[adjNode]){
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 6},
        {1, 2, 3}
    };

    int S = 2;

    vector<int> result = dijkstra(V, edges, S);

    cout << "Shortest distances from source " << S << ":\n";
    for(int i = 0; i < V; i++){
        cout << result[i] << " ";
    }

    return 0;
}
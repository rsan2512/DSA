#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {

    vector<vector<pair<int,int>>> adj(V);

    // Build graph (undirected here)
    for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(V, 1e9);
    dist[S] = 0;

    set<pair<int,int>> st; // {distance, node}
    st.insert({0, S});

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int d = it.first;
        st.erase(it);

        for(auto [adjNode, wt] : adj[node]){

            if(d + wt < dist[adjNode]){

                // remove old entry if exists
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = d + wt;
                st.insert({dist[adjNode], adjNode});
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

    cout << "Shortest distances:\n";
    for(int x : result) cout << x << " ";

    return 0;
}
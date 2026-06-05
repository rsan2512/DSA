#include <bits/stdc++.h>
using namespace std;

int Primsalgo(vector<vector<pair<int,int>>> &adj)
{
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    vector<pair<int,int>> mst;
    vector<bool> vis(adj.size(), false);

    int sum = 0;

    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        auto [wt, info] = pq.top();
        auto [node, parent] = info;
        pq.pop();

        if (vis[node]) continue;

        vis[node] = true;
        sum += wt;

        if (parent != -1)
            mst.push_back({parent, node});

        for (auto [nbr, edgeWt] : adj[node])
        {
            if (!vis[nbr])
                pq.push({edgeWt, {nbr, node}});
        }
    }

    cout << "Edges in MST:\n";
    for (auto [u, v] : mst)
    {
        cout << u << " - " << v << "\n";
    }

    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Undirected graph
    }

    int mstWeight = Primsalgo(adj);

    cout << "Total MST Weight = " << mstWeight << endl;

    return 0;
}

// example sample space:
// 5 6
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
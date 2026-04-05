#include <bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
    int V;
    public:
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfshelper(int node, vector<bool>& vis){
        vis[node]=true;
        cout << node << " ";

        for(auto it: adj[node]){
            if(!vis[it]){
                dfshelper(it, vis);
            }
        }
    }
    void dfs(int st){
        vector<bool> vis(V,false);
        dfshelper(st,vis);
    }
};
int main(){
    Graph g(5);

     g.addEdge(1,2);
     g.addEdge(2,3);
     g.addEdge(2,4);
     g.addEdge(4,0);
     g.addEdge(1,0);

    g.dfs(4);
}
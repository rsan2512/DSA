#include <bits/stdc++.h>
using namespace std;

// we use stack to store already visited nodes which are stored in stack in lifo order or they become topo order
class Solution{
public:
    void dfs(int node, vector<bool>& vis, stack<int>& s, vector<int> adj[]){
        vis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, s, adj);
        }

        s.push(node);       //last dfs pushed  into stack first
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<bool> vis(V, false);
        stack<int> s;               //a stack for lifo function 

        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, vis, s, adj);
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    int V = 6;

    vector<int> adj[V];

    // Graph:
    // 5 → 2 → 3
    // ↓         ↓
    // 0 → 1     4

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Sort: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// we use stack to store already visited nodes which are stored in stack in lifo order or they become topo order
class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int indeg[V]={0};
        for(int i=0;i<V;i++){
        for(auto it:adj[i])indeg[it]++;
        } 
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }return ans;
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
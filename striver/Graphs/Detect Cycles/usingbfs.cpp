#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    bool bfs(int st,vector<vector<int>>& adj,vector<bool>& vis){
        queue<pair<int,int>> q; //{node,parent}
        vis[st]=true;
        q.push({st,-1}); // no parent=-1

        while(!q.empty()){
            auto[node,parent]=q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){       // normal if not visited
                    vis[it]=true;
                    q.push({it,node});
                }else if(it != parent){     //if it is not the parent then it is a cycle
                    return true;    
                }
            }
        }return false;
    }
    bool isCycle(int V,vector<vector<int>>& adj){
        vector<bool> vis(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)){
                    return true;
                }
            }
        }return false;
    }
};
int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Example graph with cycle
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    Graph obj;

    if(obj.isCycle(V, adj)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
    public:
        Graph(int V){       // to intial no of edges adj list to be made in adjj
            this->V=V;
            adj.resize(V);
        }
        void addedge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void bfs(int st){
            queue<int> q;
            vector<bool> vis(V,false);
            
            vis[st]=true;
            q.push(st);
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                cout << node << " ";

                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
        }
};
int main(){
        Graph g(5);
        g.addedge(1,2);
        g.addedge(2,4);
        g.addedge(2,3);
        g.addedge(4,0);
   

        cout<<"BFS Traversal"<<endl;
        g.bfs(4);
        return 0;
}
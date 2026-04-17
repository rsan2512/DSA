#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    bool isCyclic(int N, vector<int> adj[]) {
        int indeg[N]={0};
        for(int i=0;i<N;i++){
            for(auto it: adj[i]) indeg[it]++;
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto  it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        for(int i=0;i<N;i++){
            if(indeg[i]!=0) return true;
        }return false;
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
    cout<< obj.isCyclic(V, adj);

    return 0;
}
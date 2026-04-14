#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                queue<pair<int,int>> q;
                q.push({i, 0});
                vis[i] = 0;

                while(!q.empty()) {
                    auto [node, color] = q.front();
                    q.pop();

                    for(auto it : graph[node]) {
                        if(vis[it] == -1) {
                            int newColor = 1 - color;
                            vis[it] = newColor;
                            q.push({it, newColor});
                        }
                        else {
                            if(vis[it] == color) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution obj;

    // Example graph (adjacency list)
    vector<vector<int>> graph = {
        {1,3},   // node 0
        {0,2},   // node 1
        {1,3},   // node 2
        {0,2}    // node 3
    };

    bool result = obj.isBipartite(graph);

    if(result)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
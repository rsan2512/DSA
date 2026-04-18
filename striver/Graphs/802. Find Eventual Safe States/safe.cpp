#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revgraph(n);
        vector<int> indeg(n, 0);

        // Build reverse graph
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                revgraph[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;

        // Nodes with indegree 0 (terminal nodes)
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> ans;

        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : revgraph[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    // Example graph
    // graph[i] = list of nodes i points to
    vector<vector<int>> graph = {
        {1, 2},   // 0 → 1,2
        {2, 3},   // 1 → 2,3
        {5},      // 2 → 5
        {0},      // 3 → 0 (cycle)
        {5},      // 4 → 5
        {},       // 5 → terminal
        {}        // 6 → terminal
    };

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";
    for(int x : safeNodes){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<int> indeg(N,0);
        vector<vector<int>> adj(N);

        // build graph
        for(int i=0;i<pre.size();i++){
            int x = pre[i][0];
            int y = pre[i][1];
            adj[y].push_back(x);
            indeg[x]++;
        }
        
        //if no indeg gets pushed to q
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0) q.push(i);
        }

        //bfs-kahn algo
        int count=0;        // for counting no of nodes pushed to q
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        return count==N;
    }
};

int main() {
    int numCourses = 5;

    vector<vector<int>> prerequisites = {
        {1,4}, {2,4}, {3,1}, {3,2}
    };

    Solution obj;
    bool ans = obj.canFinish(numCourses, prerequisites);

    if(ans)
        cout << "Yes, all courses can be finished.\n";
    else
        cout << "No, there is a cycle. You are academically doomed.\n";

    return 0;
}
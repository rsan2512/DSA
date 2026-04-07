#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfshelper(int node, vector<bool>& vis, vector<vector<int>>& adjm){
        vis[node]=true;
        for(int i=0;i<adjm.size();i++){
            if(adjm[node][i]==1 && !vis[i]){
                dfshelper(i, vis, adjm);
            }
        }
    }

    void dfs(int st, vector<bool>& vis, vector<vector<int>>& adjm){
        dfshelper(st, vis, adjm);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int c=0;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                c++;
            }
        }
        return c;
    }
};

int main() {
    Solution obj;

    // Example adjacency matrix
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int result = obj.findCircleNum(isConnected);

    cout << "Number of Provinces: " << result << endl;

    return 0;
}
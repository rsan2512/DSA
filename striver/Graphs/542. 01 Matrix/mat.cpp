#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, 0));

        queue<pair<pair<int,int>,int>> q;

        // Push all 0s
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }

        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};

        while(!q.empty()){
            auto [coord, k] = q.front();
            auto [x, y] = coord;
            q.pop();

            dist[x][y] = k;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({{nx,ny}, k+1});
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> result = obj.updateMatrix(mat);

    cout << "Distance Matrix:\n";
    for(auto &row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
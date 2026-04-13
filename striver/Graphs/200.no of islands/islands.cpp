#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>&  vis,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int a=0;a<4;a++){
                int nx=x+dx[a];
                int ny=y+dy[a];
                if(nx>=0 && ny>=0 && nx< grid.size() && ny< grid[0].size() && !vis[nx][ny] && grid[nx][ny]=='1'){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,vis,i,j);
                    c++;
                }
            }
        }return c;
    }
};
int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = obj.numIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m=grid.size();
        int n=grid[0].size();
        int k=grid[sr][sc];
        if(k==color) return grid;

        grid[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto[x,y]=q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];

                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=color && grid[nx][ny]==k){
                        grid[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return grid;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1;  // starting point
    int color = 2;       // new color

    vector<vector<int>> result = obj.floodFill(grid, sr, sc, color);

    cout << "Updated Grid:\n";
    for(auto &row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}